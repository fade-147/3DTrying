using NodeCanvas.Framework;
using ParadoxNotion.Design;
using UnityEngine;
using UnityEngine.AI;
using StarterAssets;

namespace NodeCanvas.Tasks.Actions
{
    /// <summary>
    /// 选择撤退目标点：远离敌人方向(70%) + 偏向最近队友方向(30%)。
    /// 结果写入黑版 retreatTarget，供 BotMoveToPosition 使用。
    /// </summary>
    [Category("Bot")]
    [Description("Pick a retreat point away from enemy and toward nearest teammate")]
    public class BotSelectRetreatPoint : ActionTask<Transform>
    {
        [BlackboardOnly] public BBParameter<Vector3> retreatTarget;
        [BlackboardOnly] public BBParameter<GameObject> targetEnemy;
        public BBParameter<float> retreatDistance = 30f;

        protected override void OnExecute()
        {
            BotController bc = agent.GetComponent<BotController>();
            if (bc == null)
            {
                EndAction(false);
                return;
            }

            // 远离敌人方向
            Vector3 awayFromEnemy = Vector3.zero;
            if (targetEnemy.value != null)
                awayFromEnemy = (agent.position - targetEnemy.value.transform.position).normalized;

            // 找最近队友方向
            Vector3 towardTeammate = Vector3.zero;
            PlayerCharacter[] all = Object.FindObjectsByType<PlayerCharacter>(FindObjectsSortMode.None);
            float nearestDist = Mathf.Infinity;
            foreach (var pc in all)
            {
                if (pc.isDead || pc.gameObject == agent.gameObject) continue;
                int t = BotController.GetTeamId(pc);
                if (t != bc.teamId) continue;
                float d = Vector3.Distance(agent.position, pc.transform.position);
                if (d < nearestDist)
                {
                    nearestDist = d;
                    towardTeammate = (pc.transform.position - agent.position).normalized;
                }
            }

            Vector3 retreatDir = (awayFromEnemy * 0.7f + towardTeammate * 0.3f).normalized;
            if (retreatDir == Vector3.zero)
                retreatDir = -agent.forward;

            Vector3 target = agent.position + retreatDir * retreatDistance.value;
            if (NavMesh.SamplePosition(target, out NavMeshHit hit, 20f, NavMesh.AllAreas))
                retreatTarget.value = hit.position;
            else
                retreatTarget.value = agent.position - agent.forward * 15f;

            bc.SetAwareness(AwarenessLevel.Engaged);
            EndAction(true);
        }
    }
}
