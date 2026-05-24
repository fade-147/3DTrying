using NodeCanvas.Framework;
using ParadoxNotion.Design;
using UnityEngine;

namespace NodeCanvas.Tasks.Actions
{
    [Category("Bot")]
    [Description("Heal the bot by calling PlayerCharacter.Heal() on the server")]
    public class BotHealAction : ActionTask<Transform>
    {
        public BBParameter<float> amount = 30f;

        private PlayerCharacter _playerChar;

        protected override string info
        {
            get { return $"Heal {amount.value} HP"; }
        }

        protected override void OnExecute()
        {
            if (_playerChar == null)
                _playerChar = agent.GetComponent<PlayerCharacter>();

            if (_playerChar != null)
            {
                _playerChar.Heal(amount.value);
            }

            EndAction(true);
        }
    }
}
