using NodeCanvas.Framework;
using ParadoxNotion.Design;
using UnityEngine;

namespace NodeCanvas.Tasks.Actions
{
    [Category("Bot")]
    [Description("Set BotController.isDrinking and update Animator parameter")]
    public class BotSetDrinkingAction : ActionTask<Transform>
    {
        public bool setTo = true;

        private static readonly int IsDrinkingHash = Animator.StringToHash("IsDrinking");

        protected override string info
        {
            get { return $"IsDrinking = {setTo}"; }
        }

        protected override void OnExecute()
        {
            BotController bc = agent.GetComponent<BotController>();
            if (bc != null)
            {
                bc.isDrinking = setTo;
            }

            Animator anim = agent.GetComponent<Animator>();
            if (anim != null)
            {
                anim.SetBool(IsDrinkingHash, setTo);
            }

            EndAction(true);
        }
    }
}
