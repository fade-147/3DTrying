using NodeCanvas.Framework;
using ParadoxNotion.Design;
using UnityEngine;

namespace NodeCanvas.Tasks.Actions
{
    [Category("Bot")]
    [Description("Refill BotController currentAmmo to MaxAmmo")]
    public class BotRefillAmmoAction : ActionTask<Transform>
    {
        protected override string info
        {
            get { return "Refill Ammo"; }
        }

        protected override void OnExecute()
        {
            BotController bc = agent.GetComponent<BotController>();
            if (bc != null)
            {
                bc.currentAmmo = BotController.MaxAmmo;
            }

            EndAction(true);
        }
    }
}
