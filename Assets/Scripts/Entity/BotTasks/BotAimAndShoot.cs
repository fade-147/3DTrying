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
        public float aimSmoothTime = 0.1f;
        public float preferredDistance = 15f;

        private BotController _botController;
        private NavMeshAgent _navAgent;
        private float _fireTimer;
        private float _lostTimer;
        private float _noLOSTimer;
        private int _layerMask;

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

            // 射击冷却
            if (_fireTimer > 0f)
                _fireTimer -= Time.deltaTime;

            // LOS 检测
            Vector3 dirToTarget = (target.position - agent.position).normalized;
            Vector3 muzzlePos = _botController.GetMuzzlePosition();
            Vector3 aimTarget = target.position + Vector3.up * aimHeight;
            Vector3 shootDirection = (aimTarget - muzzlePos).normalized;
            bool hasLOS = !Physics.Raycast(muzzlePos, shootDirection, dist, _layerMask);

            if (hasLOS)
            {
                _noLOSTimer = 0f;

                // 有视野：停在 preferredDistance 处射击
                if (_navAgent != null && _navAgent.isOnNavMesh)
                {
                    Vector3 desiredPos = target.position - dirToTarget * preferredDistance;
                    if (NavMesh.SamplePosition(desiredPos, out NavMeshHit hit, 5f, NavMesh.AllAreas))
                    {
                        _navAgent.stoppingDistance = 0.5f;
                        _navAgent.SetDestination(hit.position);
                    }
                }

                if (_fireTimer <= 0f && dist <= effectiveRange.value)
                {
                    _botController.ServerFire(_botController.ApplySpread(shootDirection), muzzlePos);
                    _botController.ConsumeAmmo();
                    _fireTimer = fireRate.value;
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
        }

        protected override void OnPause() { }

        protected override void OnStop()
        {
            _botController = null;
        }
    }
}
