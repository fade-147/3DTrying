using NodeCanvas.Framework;
using ParadoxNotion.Design;
using UnityEngine;
using StarterAssets;

namespace NodeCanvas.Tasks.Actions
{
    /// <summary>
    /// 查找最近的不同队伍玩家作为目标敌人，结果写入黑版 targetEnemy。
    /// </summary>
    [Category("Bot")]
    [Description("Find the nearest enemy player on opposing team and write to blackboard variable 'targetEnemy'")]
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

            ThirdPersonController[] allPlayers = Object.FindObjectsByType<ThirdPersonController>(FindObjectsSortMode.None);
            foreach (ThirdPersonController player in allPlayers)
            {
                if (player.teamId == botController.teamId) continue;

                PlayerCharacter pc = player.GetComponent<PlayerCharacter>();
                if (pc != null && pc.isDead) continue;

                float dist = Vector3.Distance(agent.position, player.transform.position);
                if (dist < nearestDist)
                {
                    nearestDist = dist;
                    nearest = player.gameObject;
                }
            }

            targetEnemy.value = nearest;
            EndAction(nearest != null);
        }
    }
}
