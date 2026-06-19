using NodeCanvas.Framework;
using ParadoxNotion.Design;
using UnityEngine;
using StarterAssets;

namespace NodeCanvas.Tasks.Actions
{
    /// <summary>
    /// 查找最近的不同队伍目标（玩家或人机），结果写入黑版 targetEnemy。
    /// 搜索 PlayerCharacter 组件（玩家和人机都有），再从 BotController 或 ThirdPersonController 获取 teamId。
    /// </summary>
    [Category("Bot")]
    [Description("Find the nearest enemy (player or bot) on opposing team and write to blackboard variable 'targetEnemy'")]
    public class BotFindEnemy : ActionTask<Transform>
    {
        [BlackboardOnly]
        public BBParameter<GameObject> targetEnemy;

        protected override void OnExecute()
        {
            BotController botController = agent.GetComponent<BotController>();
            if (botController == null)
            {
                EndAction(false);
                return;
            }

            GameObject nearest = null;
            float nearestDist = Mathf.Infinity;

            // 根据感知等级确定检测距离和视野锥
            float detectRange = botController.GetCurrentDetectionRange();
            float visionHalfAngle = botController.GetCurrentVisionHalfAngle();

            PlayerCharacter[] allChars = Object.FindObjectsByType<PlayerCharacter>(FindObjectsSortMode.None);
            foreach (PlayerCharacter pc in allChars)
            {
                if (pc.isDead) continue;
                if (pc.gameObject == agent.gameObject) continue;

                int otherTeamId = BotController.GetTeamId(pc);
                if (otherTeamId == -1 || otherTeamId == botController.teamId) continue;

                float dist = Vector3.Distance(agent.position, pc.transform.position);
                if (dist > detectRange) continue; // 距离限制

                // 视野锥检测（Engaged 时 180° 即全方向）
                if (visionHalfAngle < 180f)
                {
                    Vector3 dirToTarget = (pc.transform.position - agent.position).normalized;
                    float angle = Vector3.Angle(agent.forward, dirToTarget);
                    if (angle > visionHalfAngle) continue;
                }

                if (dist < nearestDist)
                {
                    nearestDist = dist;
                    nearest = pc.gameObject;
                }
            }

            targetEnemy.value = nearest;

            if (nearest != null)
                botController.SetAwareness(AwarenessLevel.Aware);

            EndAction(nearest != null);
        }
    }
}
