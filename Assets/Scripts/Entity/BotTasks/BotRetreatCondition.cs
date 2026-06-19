using NodeCanvas.Framework;
using ParadoxNotion.Design;
using UnityEngine;

namespace NodeCanvas.Tasks.Conditions
{
    /// <summary>
    /// 血量低于阈值时触发撤退。有冷却时间防止重复触发。
    /// </summary>
    [Category("Bot")]
    [Description("Condition: health below threshold and retreat cooldown elapsed")]
    public class BotRetreatCondition : ConditionTask<Transform>
    {
        public BBParameter<float> healthPercent = 0.25f;
        public BBParameter<float> retreatCooldown = 15f;

        private PlayerCharacter _pc;
        private float _lastRetreatTime = -999f;

        protected override bool OnCheck()
        {
            if (_pc == null)
                _pc = agent.GetComponent<PlayerCharacter>();

            if (_pc == null) return false;

            // 冷却中不重复撤退
            if (Time.time - _lastRetreatTime < retreatCooldown.value) return false;

            if (_pc.CurrentHealth < _pc.MaxHealth * healthPercent.value)
            {
                _lastRetreatTime = Time.time;
                return true;
            }

            return false;
        }
    }
}
