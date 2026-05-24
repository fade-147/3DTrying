using NodeCanvas.Framework;
using ParadoxNotion.Design;
using UnityEngine;

namespace NodeCanvas.Tasks.Conditions
{
    [Category("Bot")]
    [Description("Check PlayerCharacter health against a threshold")]
    public class BotCheckHealth : ConditionTask<Transform>
    {
        public BBParameter<float> threshold = 40f;
        public int checkType = 2; // 0:==, 1:>, 2:<, 3:>=, 4:<=

        private PlayerCharacter _playerChar;

        protected override string info
        {
            get
            {
                string op = checkType switch { 0 => "==", 1 => ">", 2 => "<", 3 => ">=", 4 => "<=", _ => "?" };
                return $"Health {op} {threshold.value}";
            }
        }

        protected override void OnEnable()
        {
            _playerChar = agent.GetComponent<PlayerCharacter>();
        }

        protected override bool OnCheck()
        {
            if (_playerChar == null) return false;

            float current = _playerChar.CurrentHealth;
            return checkType switch
            {
                0 => Mathf.Approximately(current, threshold.value),
                1 => current > threshold.value,
                2 => current < threshold.value,
                3 => current >= threshold.value,
                4 => current <= threshold.value,
                _ => false,
            };
        }
    }
}
