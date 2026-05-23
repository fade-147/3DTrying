using NodeCanvas.Framework;
using ParadoxNotion.Design;
using UnityEngine;

namespace NodeCanvas.Tasks.Actions
{
    /// <summary>
    /// 每帧平滑瞄准目标敌人并射击。多帧任务，持续运行直到失去目标或弹药耗尽。
    /// </summary>
    [Category("Bot")]
    [Description("Smoothly aim at target enemy and shoot every fireRate seconds")]
    public class BotAimAndShoot : ActionTask<Transform>
    {
        public BBParameter<GameObject> targetEnemy;
        public BBParameter<float> fireRate = 0.2f;
        public float aimSmoothTime = 0.1f;

        private BotController _botController;
        private float _fireTimer;

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
            _fireTimer = 0f;
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

            // 平滑瞄准（委托给 BotController，避免重复实现）
            _botController.AimAtTarget(targetObj.transform);

            // 射击冷却更新
            if (_fireTimer > 0f)
            {
                _fireTimer -= Time.deltaTime;
                return;
            }

            // 发射子弹
            Vector3 muzzlePos = _botController.GetMuzzlePosition();
            Vector3 shootDirection = (targetObj.transform.position - muzzlePos).normalized;

            _botController.CmdFire(shootDirection, muzzlePos);
            _botController.ConsumeAmmo();
            _fireTimer = fireRate.value;
        }

        protected override void OnPause() { }

        protected override void OnStop()
        {
            _botController = null;
        }
    }
}
