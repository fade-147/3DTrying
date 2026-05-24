using NodeCanvas.Framework;
using ParadoxNotion.Design;
using UnityEngine;

namespace NodeCanvas.Tasks.Actions
{
    [Category("Bot")]
    [Description("Set BotController.isReloading SyncVar")]
    public class BotSetReloadingAction : ActionTask<Transform>
    {
        public bool setTo = true;

        protected override string info
        {
            get { return $"IsReloading = {setTo}"; }
        }

        protected override void OnExecute()
        {
            BotController bc = agent.GetComponent<BotController>();
            if (bc != null)
            {
                bc.isReloading = setTo;
            }

            EndAction(true);
        }
    }
}
