using NodeCanvas.Framework;
using ParadoxNotion.Design;
using UnityEngine;

namespace NodeCanvas.Tasks.Conditions
{
    [Category("Bot")]
    [Description("Check if Bot is currently reloading")]
    public class BotCheckIsReloading : ConditionTask<Transform>
    {
        public bool expectValue = false;

        private BotController _botController;

        protected override string info
        {
            get { return $"IsReloading == {expectValue}"; }
        }

        protected override void OnEnable()
        {
            _botController = agent.GetComponent<BotController>();
        }

        protected override bool OnCheck()
        {
            if (_botController == null) return false;
            return _botController.isReloading == expectValue;
        }
    }
}
