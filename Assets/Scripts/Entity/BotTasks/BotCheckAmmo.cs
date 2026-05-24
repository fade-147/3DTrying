using NodeCanvas.Framework;
using ParadoxNotion.Design;
using UnityEngine;

namespace NodeCanvas.Tasks.Conditions
{
    [Category("Bot")]
    [Description("Check BotController ammo against a threshold")]
    public class BotCheckAmmo : ConditionTask<Transform>
    {
        public BBParameter<float> threshold = 0f;
        public int checkType = 4; // 0:==, 1:>, 2:<, 3:>=, 4:<=

        private BotController _botController;

        protected override string info
        {
            get
            {
                string op = checkType switch { 0 => "==", 1 => ">", 2 => "<", 3 => ">=", 4 => "<=", _ => "?" };
                return $"Ammo {op} {threshold.value}";
            }
        }

        protected override void OnEnable()
        {
            _botController = agent.GetComponent<BotController>();
        }

        protected override bool OnCheck()
        {
            if (_botController == null) return false;

            float ammo = _botController.currentAmmo;
            return checkType switch
            {
                0 => Mathf.Approximately(ammo, threshold.value),
                1 => ammo > threshold.value,
                2 => ammo < threshold.value,
                3 => ammo >= threshold.value,
                4 => ammo <= threshold.value,
                _ => false,
            };
        }
    }
}
