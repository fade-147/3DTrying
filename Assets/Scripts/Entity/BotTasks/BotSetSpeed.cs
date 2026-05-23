using NodeCanvas.Framework;
using ParadoxNotion.Design;
using UnityEngine;
using UnityEngine.AI;

namespace NodeCanvas.Tasks.Actions
{
    /// <summary>
    /// 设置 NavMeshAgent 的速度倍率。换弹时 0.9 减速，喝药时 0 停下。
    /// </summary>
    [Category("Bot")]
    [Description("Set the NavMeshAgent speed multiplier. 0 = stop, 0.9 = slow for reload, 1.0 = normal")]
    public class BotSetSpeed : ActionTask<Transform>
    {
        /// <summary>
        /// 速度倍率，1.0 为原始速度。
        /// </summary>
        public BBParameter<float> speedMultiplier = 1f;

        protected override void OnExecute()
        {
            NavMeshAgent navAgent = agent.GetComponent<NavMeshAgent>();
            BotController botController = agent.GetComponent<BotController>();

            if (navAgent == null)
            {
                EndAction(false);
                return;
            }

            if (botController != null)
            {
                botController.SetSpeedMultiplier(speedMultiplier.value);
            }
            else
            {
                // 回退：直接设置 NavMeshAgent 速度，按 3.5 基准估算
                navAgent.speed = 3.5f * speedMultiplier.value;
            }

            EndAction(true);
        }
    }
}
