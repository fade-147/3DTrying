using NodeCanvas.Framework;
using ParadoxNotion.Design;
using UnityEngine;

namespace NodeCanvas.Tasks.Actions
{
    /// <summary>
    /// 为 Bot 选择一个智能巡逻点，写入 patrolTarget。
    /// 由 BotController.PickPatrolPoint() 实现巡逻记忆。
    /// </summary>
    [Category("Bot")]
    [Description("Pick a smart patrol waypoint, avoiding recently visited areas")]
    public class BotPickPatrolPoint : ActionTask<Transform>
    {
        [BlackboardOnly]
        public BBParameter<Vector3> patrolTarget;

        private BotController _bc;

        protected override void OnExecute()
        {
            _bc = agent.GetComponent<BotController>();
            if (_bc == null)
            {
                EndAction(false);
                return;
            }

            patrolTarget.value = _bc.PickPatrolPoint();
            EndAction(true);
        }
    }
}
