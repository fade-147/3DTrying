using NodeCanvas.Framework;
using ParadoxNotion.Design;
using UnityEngine;
using UnityEngine.AI;

namespace NodeCanvas.Tasks.Actions
{
    [Category("Bot")]
    [Description("Move to target position. Periodically scans for enemies and exits if found.")]
    public class BotMoveToPosition : ActionTask<Transform>
    {
        public BBParameter<Vector3> targetPosition;
        public BBParameter<float> speed = 4f;
        public BBParameter<float> keepDistance = 0.5f;

        private const float MoveTimeout = 30f;
        private const float RescanInterval = 1.5f;
        private const float StartupGracePeriod = 0.5f;
        private const float MidPathInterval = 4f;

        private NavMeshAgent _navAgent;
        private BotController _botController;
        private Blackboard _blackboard;
        private float _elapsedTime;
        private float _rescanTimer;
        private float _graceTimer;
        private float _midPathTimer;
        private Vector3 _lastTarget;
        private Vector3 _projectedDest;
        private Vector3 _currentDest;
        private int _setDestFailCount;

        protected override void OnExecute()
        {
            _navAgent = agent.GetComponent<NavMeshAgent>();
            _botController = agent.GetComponent<BotController>();
            _blackboard = agent.GetComponent<Blackboard>();
            _elapsedTime = 0f;
            _rescanTimer = 0f; // 首次扫描延迟 1.5s，防止刚进入巡逻就因残留 targetEnemy 退出
            _midPathTimer = 0f;

            // 目标没变则不重置宽限期，防止树重置时反复归零
            if (targetPosition.value != _lastTarget)
            {
                _graceTimer = 0f;
                _lastTarget = targetPosition.value;
                _projectedDest = targetPosition.value;
                _currentDest = Vector3.zero;
            }
            _setDestFailCount = 0;

            Debug.Log($"[BotMoveToPosition] OnExecute: target={targetPosition.value}, agentOnNavMesh={_navAgent != null && _navAgent.isOnNavMesh}, speed={(_navAgent != null ? _navAgent.speed : -1)}, isStopped={_navAgent != null && _navAgent.isStopped}, botTeamId={(_botController != null ? _botController.teamId : -1)}, pos={agent.position}");
        }

        protected override void OnUpdate()
        {
            _elapsedTime += Time.deltaTime;
            if (_elapsedTime > MoveTimeout)
            {
                EndAction(false);
                return;
            }

            // 定期扫描敌人：发现有效目标则退出巡逻，让 Selector 流转到战斗分支
            // 使用 GetVariable 替代 GetVariableValue<T>，避免变量不存在时产生错误日志
            _rescanTimer += Time.deltaTime;
            if (_rescanTimer > RescanInterval)
            {
                _rescanTimer = 0f;
                if (_botController != null && _blackboard != null)
                {
                    _botController.FindTargetEnemy();
                    var targetVar = _blackboard.GetVariable(BotController.TargetEnemyVarName, typeof(GameObject));
                    if (targetVar != null && targetVar.value is GameObject target && target != null)
                    {
                        EndAction(false);
                        return;
                    }
                }
            }

            if (_navAgent == null || !_navAgent.isOnNavMesh)
                return;

            // 将目标投影到 NavMesh 表面，确保可达
            Vector3 dest = targetPosition.value;
            if (NavMesh.SamplePosition(dest, out NavMeshHit navHit, 10f, NavMesh.AllAreas))
                dest = navHit.position;

            // 中途随机偏移：每隔 MidPathInterval 秒对路径做小扰动，让 Bot 路线差异化
            if (_navAgent != null && _navAgent.isOnNavMesh)
            {
                _midPathTimer += Time.deltaTime;
                if (_midPathTimer > MidPathInterval)
                {
                    _midPathTimer = 0f;
                    Vector3 midPoint = agent.position + Quaternion.Euler(0, Random.Range(-30f, 30f), 0)
                        * (dest - agent.position).normalized * Random.Range(5f, 10f);
                    if (NavMesh.SamplePosition(midPoint, out NavMeshHit midHit, 5f, NavMesh.AllAreas))
                        _currentDest = midHit.position;
                }
            }

            _navAgent.speed = speed.value;
            _navAgent.stoppingDistance = keepDistance.value;
            Vector3 finalDest = _currentDest != Vector3.zero ? _currentDest : dest;
            bool pathFound = _navAgent.SetDestination(finalDest);
            if (pathFound)
                _projectedDest = dest;

            if (!pathFound)
            {
                _setDestFailCount++;
                if (_setDestFailCount % 60 == 1) // 每60帧≈1秒报一次
                    Debug.LogWarning($"[BotMoveToPosition] SetDestination FAILED x{_setDestFailCount}: dest={dest}, agentPos={agent.position}, isOnNavMesh={_navAgent.isOnNavMesh}, pathStatus={_navAgent.pathStatus}");
            }

            _graceTimer += Time.deltaTime;
            if (_graceTimer < StartupGracePeriod)
                return;

            // 到达判定：路径计算完毕 + 剩余距离在阈值内 + 实际距离也接近目标
            // 双重校验防止 remainingDistance==0 导致的假到达（agent 未启动/无有效路径时）
            if (!_navAgent.pathPending && _navAgent.remainingDistance <= _navAgent.stoppingDistance)
            {
                float directDist = Vector3.Distance(agent.position, _projectedDest);
                if (directDist <= _navAgent.stoppingDistance + 0.5f)
                {
                    if (_botController != null)
                        _botController.ArriveAtZone();
                    EndAction(true);
                }
            }
        }

        protected override void OnPause() { }
        protected override void OnStop() { _navAgent = null; }
    }
}
