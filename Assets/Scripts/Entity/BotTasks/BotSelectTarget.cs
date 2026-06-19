using NodeCanvas.Framework;
using ParadoxNotion.Design;
using UnityEngine;
using StarterAssets;

namespace NodeCanvas.Tasks.Actions
{
    /// <summary>
    /// 持续评估所有敌人，动态选择最佳目标写入 targetEnemy。
    /// 威胁评分：距离(50%) + 角度(30%) + 视野(20%)，滞后切换防止震荡。
    /// 无目标时返回 Failure，触发退出战斗。
    /// </summary>
    [Category("Bot")]
    [Description("Continuously re-evaluate all enemies with threat scoring and hysteresis")]
    public class BotSelectTarget : ActionTask<Transform>
    {
        [BlackboardOnly]
        public BBParameter<GameObject> targetEnemy;
        public BBParameter<float> reEvaluateInterval = 0.5f;
        public BBParameter<float> maxDistance = 50f;
        public BBParameter<float> switchThreshold = 0.2f;

        private BotController _bc;
        private float _timer;
        private int _layerMask;

        protected override void OnExecute()
        {
            _bc = agent.GetComponent<BotController>();
            if (_bc == null)
            {
                EndAction(false);
                return;
            }
            _layerMask = LayerMask.GetMask("Default", "Environment");
            _timer = 0f;

            targetEnemy.value = SelectBestTarget();
            if (targetEnemy.value == null)
            {
                EndAction(false);
            }
        }

        protected override void OnUpdate()
        {
            _timer += Time.deltaTime;
            if (_timer < reEvaluateInterval.value) return;
            _timer = 0f;

            targetEnemy.value = SelectBestTarget();
            if (targetEnemy.value == null)
            {
                EndAction(false);
            }
        }

        private GameObject SelectBestTarget()
        {
            GameObject best = null;
            float bestScore = 0f;
            GameObject current = targetEnemy.value;

            // 当前目标已死亡则放弃惯性保护
            if (current != null)
            {
                PlayerCharacter currentPc = current.GetComponent<PlayerCharacter>();
                if (currentPc != null && currentPc.isDead)
                    current = null;
            }

            PlayerCharacter[] all = Object.FindObjectsByType<PlayerCharacter>(FindObjectsSortMode.None);
            foreach (PlayerCharacter pc in all)
            {
                if (pc.isDead) continue;
                if (pc.gameObject == agent.gameObject) continue;

                int otherTeam = BotController.GetTeamId(pc);
                if (otherTeam < 0 || otherTeam == _bc.teamId) continue;

                float score = ScoreTarget(pc.transform);
                if (score < 0f) continue;
                if (score > bestScore)
                {
                    bestScore = score;
                    best = pc.gameObject;
                }
            }

            if (best == null) return null;

            // 滞后切换：当前目标有惯性优势，需新目标超出阈值才切换
            if (current != null && best != current)
            {
                float currentScore = ScoreTarget(current.transform);
                if (currentScore > 0f && bestScore < currentScore * (1f + switchThreshold.value))
                    return current;
            }

            return best;
        }

        private float ScoreTarget(Transform enemy)
        {
            float dist = Vector3.Distance(agent.position, enemy.position);
            if (dist > maxDistance.value) return -1f;

            Vector3 dirToEnemy = (enemy.position - agent.position).normalized;
            float angle = Vector3.Angle(agent.forward, dirToEnemy);

            // 视野锥过滤：目标在锥外则大幅降权（Engaged 180° 全方向不降权）
            if (_bc != null)
            {
                float halfAngle = _bc.GetCurrentVisionHalfAngle();
                if (halfAngle < 180f && angle > halfAngle)
                    return -1f;
            }

            float score = 0f;
            score += (1f - dist / maxDistance.value) * 50f;
            score += (1f - angle / 180f) * 30f;
            if (CheckLOS(enemy.position)) score += 20f;

            return score;
        }

        private bool CheckLOS(Vector3 targetPos)
        {
            Vector3 origin = agent.position + Vector3.up * 1.5f;
            Vector3 targetPoint = targetPos + Vector3.up * 1.5f;
            Vector3 dir = targetPoint - origin;
            return !Physics.Raycast(origin, dir.normalized, dir.magnitude, _layerMask);
        }

        protected override void OnPause() { }

        protected override void OnStop()
        {
            _bc = null;
        }
    }
}
