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

        private NavMeshAgent _navAgent;
        private BotController _botController;
        private Blackboard _blackboard;
        private float _elapsedTime;
        private float _rescanTimer;

        protected override void OnExecute()
        {
            _navAgent = agent.GetComponent<NavMeshAgent>();
            _botController = agent.GetComponent<BotController>();
            _blackboard = agent.GetComponent<Blackboard>();
            _elapsedTime = 0f;
            _rescanTimer = RescanInterval; // 首帧立即扫描，防止向错误方向移动
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

            _navAgent.speed = speed.value;
            _navAgent.stoppingDistance = keepDistance.value;
            _navAgent.SetDestination(targetPosition.value);

            if (!_navAgent.pathPending && _navAgent.remainingDistance <= _navAgent.stoppingDistance)
                EndAction(true);
        }

        protected override void OnPause() { }
        protected override void OnStop() { _navAgent = null; }
    }
}
