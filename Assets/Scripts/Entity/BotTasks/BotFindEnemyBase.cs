using NodeCanvas.Framework;
using ParadoxNotion.Design;
using UnityEngine;

namespace NodeCanvas.Tasks.Actions
{
    /// <summary>
    /// 查找敌方基地位置和生成随机侧翼偏移向量，结果写入黑版 enemyBasePos 和 flankOffset。
    /// </summary>
    [Category("Bot")]
    [Description("Find enemy base by tag and generate a random flank offset for path diversity")]
    public class BotFindEnemyBase : ActionTask<Transform>
    {
        private const string RedBaseTag = "RedBase";
        private const string BlueBaseTag = "BlueBase";

        [BlackboardOnly]
        public BBParameter<Vector3> enemyBasePos;

        [BlackboardOnly]
        public BBParameter<Vector3> flankOffset;

        [BlackboardOnly]
        public BBParameter<Vector3> moveTarget;

        /// <summary>
        /// 侧翼偏移的最大距离。
        /// </summary>
        public BBParameter<float> flankRange = 5f;

        protected override void OnExecute()
        {
            BotController botController = agent.GetComponent<BotController>();
            if (botController == null)
            {
                EndAction(false);
                return;
            }

            string enemyTag = botController.teamId == 0 ? BlueBaseTag : RedBaseTag;
            GameObject enemyBase = GameObject.FindGameObjectWithTag(enemyTag);

            if (enemyBase != null)
            {
                enemyBasePos.value = enemyBase.transform.position;
            }
            else
            {
                // 未找到基地标记时回退到原点
                enemyBasePos.value = Vector3.zero;
            }

            // 生成随机侧翼偏移，让多个 Bot 走不同路径
            flankOffset.value = new Vector3(
                Random.Range(-flankRange.value, flankRange.value),
                0f,
                Random.Range(-flankRange.value * 0.6f, flankRange.value * 0.6f)
            );

            // 计算最终移动目标 = 基地位置 + 侧翼偏移
            moveTarget.value = enemyBasePos.value + flankOffset.value;

            EndAction(true);
        }
    }
}
