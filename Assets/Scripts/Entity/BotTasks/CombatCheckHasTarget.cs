using NodeCanvas.Framework;
using ParadoxNotion.Design;
using UnityEngine;

namespace NodeCanvas.Tasks.Conditions
{
    [Category("Bot")]
    [Description("Check if targetEnemy is assigned in the blackboard")]
    public class CombatCheckHasTarget : ConditionTask<Transform>
    {
        [BlackboardOnly]
        public BBParameter<GameObject> targetEnemy;

        protected override bool OnCheck()
        {
            return targetEnemy.value != null;
        }
    }
}
