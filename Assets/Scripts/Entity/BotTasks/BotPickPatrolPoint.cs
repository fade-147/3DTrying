using NodeCanvas.Framework;
using ParadoxNotion.Design;
using UnityEngine;

namespace NodeCanvas.Tasks.Actions
{
    /// <summary>
    /// 从场景 StrategyZone 中智能选择一个目标区，写入 patrolTarget。
    /// 如果场景无 StrategyZone，回退到 NavMesh 随机巡逻。
    /// </summary>
    [Category("Bot")]
    [Description("Pick a strategy zone (or random NavMesh point as fallback) as patrol target")]
    public class BotPickPatrolPoint : ActionTask<Transform>
    {
        [BlackboardOnly]
        public BBParameter<Vector3> patrolTarget;

        // 回退：NavMesh 随机巡逻参数
        public BBParameter<float> fallbackRadius = 30f;

        private BotController _bc;
        private StrategyZone _chosenZone;

        protected override void OnExecute()
        {
            _bc = agent.GetComponent<BotController>();
            if (_bc == null)
            {
                Debug.LogWarning("[BotPickPatrolPoint] OnExecute: BotController NOT FOUND on agent");
                EndAction(false);
                return;
            }

            Debug.Log($"[BotPickPatrolPoint] OnExecute: teamId={_bc.teamId}, allZones count={StrategyZone.AllZones.Count}, pos={agent.position}");

            _chosenZone = _bc.PickStrategyZone();

            if (_chosenZone != null)
            {
                patrolTarget.value = _chosenZone.WorldPosition;
                Debug.Log($"[BotPickPatrolPoint] OnExecute: zone={_chosenZone.name}, type={_chosenZone.zoneType}, sideAssignment={_chosenZone.sideAssignment}, pos={_chosenZone.WorldPosition}");
                EndAction(true);
            }
            else
            {
                // 回退：场景没有 StrategyZone 或没有对该 team 有效的区
                Vector3 fallback = _bc.PickPatrolPoint();
                patrolTarget.value = fallback;
                Debug.Log($"[BotPickPatrolPoint] OnExecute: no zone selected, fallback patrol={fallback}");
                EndAction(true);
            }
        }

        protected override void OnStop()
        {
            // 不在此处释放 zone 认领——ArriveAtZone 由 BotMoveToPosition 到达时调用
        }
    }
}
