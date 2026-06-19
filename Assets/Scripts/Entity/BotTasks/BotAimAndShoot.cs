using NodeCanvas.Framework;
using ParadoxNotion.Design;
using UnityEngine;
using UnityEngine.AI;

namespace NodeCanvas.Tasks.Actions
{
    [Category("Bot")]
    [Description("Aim at target, approach via NavMesh, shoot when LOS is clear")]
    public class BotAimAndShoot : ActionTask<Transform>
    {
        public BBParameter<GameObject> targetEnemy;
        public BBParameter<float> fireRate = 0.35f;
        public BBParameter<float> effectiveRange = 30f;
        public BBParameter<float> maxChaseDistance = 60f;
        public BBParameter<float> lostTargetTimeout = 5f;
        public BBParameter<float> noLOSTimeout = 8f;
        public float aimHeight = 1.5f;
        public float preferredDistance = 15f;

        private BotController _botController;
        private NavMeshAgent _navAgent;
        private float _fireTimer;
        private float _lostTimer;
        private float _noLOSTimer;
        private int _layerMask;
        private int _consecutiveShots;
        private const float ConsecutiveShotPenaltyPerShot = 0.05f;

        protected override string info
        {
            get { return "Aim & Shoot " + (targetEnemy.value != null ? targetEnemy.value.name : "null"); }
        }

        protected override void OnExecute()
        {
            _botController = agent.GetComponent<BotController>();
            if (_botController == null)
            {
                EndAction(false);
                return;
            }
            _navAgent = agent.GetComponent<NavMeshAgent>();
            _layerMask = LayerMask.GetMask("Default", "Environment");
            _fireTimer = 0f;
            _lostTimer = 0f;
            _noLOSTimer = 0f;
            _consecutiveShots = -2; // 前2发精度加成：第1发 +0.2, 第2发 +0.1
        }

        protected override void OnUpdate()
        {
            GameObject targetObj = targetEnemy.value;
            if (targetObj == null)
            {
                EndAction(false);
                return;
            }

            if (!_botController.HasAmmo())
            {
                EndAction(false);
                return;
            }

            Transform target = targetObj.transform;
            float dist = Vector3.Distance(agent.position, target.position);

            // 目标太远，计时丢失
            if (dist > maxChaseDistance.value)
            {
                _lostTimer += Time.deltaTime;
                if (_lostTimer > lostTargetTimeout.value)
                {
                    EndAction(false);
                    return;
                }
            }
            else
            {
                _lostTimer = 0f;
            }

            // 始终瞄准目标
            _botController.AimAtTarget(target);

            // 射击冷却 + 感知衰减
            _botController.UpdateTimers();
            if (_fireTimer > 0f) _fireTimer -= Time.deltaTime;

            // LOS 检测
            Vector3 dirToTarget = (target.position - agent.position).normalized;
            Vector3 muzzlePos = _botController.GetMuzzlePosition();
            Vector3 aimTarget = target.position + Vector3.up * aimHeight;
            Vector3 shootDirection = (aimTarget - muzzlePos).normalized;
            bool hasLOS = !Physics.Raycast(muzzlePos, shootDirection, dist, _layerMask);

            if (hasLOS)
            {
                _noLOSTimer = 0f;

                // 有视野：停在 preferredDistance 处射击（NavMesh 并行移动不阻断射击）
                if (_navAgent != null && _navAgent.isOnNavMesh)
                {
                    Vector3 desiredPos = target.position - dirToTarget * preferredDistance;
                    if (NavMesh.SamplePosition(desiredPos, out NavMeshHit hit, 5f, NavMesh.AllAreas))
                    {
                        _navAgent.stoppingDistance = 0.5f;
                        _navAgent.SetDestination(hit.position);
                    }
                }

                if (_botController.CanFire() && dist <= effectiveRange.value)
                {
                    // 动态精度：根据移动状态调整命中率和散布
                    _botController.GetDynamicAccuracy(out float hp, out float spread);

                    // 距离衰减：超过 40 单位精度下降
                    if (dist > 40f)
                    {
                        hp *= 0.7f;
                        spread *= 1.5f;
                    }

                    // 前 2 发精度加成（_consecutiveShots 从 -2 开始）
                    float shotBonus = 0f;
                    if (_consecutiveShots < 0)
                    {
                        shotBonus = Mathf.Abs(_consecutiveShots) * 0.1f;
                        hp = Mathf.Min(1f, hp + shotBonus);
                    }

                    // 连续射击递减
                    hp = Mathf.Max(0.1f, hp - _consecutiveShots * ConsecutiveShotPenaltyPerShot);
                    spread *= 1f + _consecutiveShots * 0.08f;

                    _botController.ServerFire(
                        _botController.ApplySpread(shootDirection, hp, spread),
                        muzzlePos);
                    _botController.ConsumeAmmo();
                    _fireTimer = fireRate.value;
                    _consecutiveShots++;
                }
            }
            else
            {
                // 无视野：NavMesh 自动寻路靠近目标
                _noLOSTimer += Time.deltaTime;

                if (_noLOSTimer > noLOSTimeout.value)
                {
                    EndAction(false);
                    return;
                }

                if (_navAgent != null && _navAgent.isOnNavMesh)
                {
                    _navAgent.stoppingDistance = preferredDistance;
                    _navAgent.SetDestination(target.position);
                }
            }

            // 半射速周期内未射击则重置连续计数
            if (_fireTimer > 0f && _fireTimer <= fireRate.value * 0.5f)
                _consecutiveShots = 0;
        }

        protected override void OnPause() { }

        protected override void OnStop()
        {
            _botController = null;
        }
    }
}
