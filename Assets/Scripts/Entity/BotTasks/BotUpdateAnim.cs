using NodeCanvas.Framework;
using ParadoxNotion.Design;
using UnityEngine;
using UnityEngine.AI;

namespace NodeCanvas.Tasks.Actions
{
    [Category("Bot")]
    [Description("Directly control Animator states for bot locomotion")]
    public class BotUpdateAnim : ActionTask<Transform>
    {
        private NavMeshAgent _navAgent;
        private Animator _animator;
        private bool _isMoving;

        private static readonly int IsHoldingGunHash = Animator.StringToHash("IsHoldingGun");
        private static readonly int MoveForwardHash = Animator.StringToHash("MoveForward");
        private const float MoveSpeedThreshold = 0.1f;

        protected override void OnExecute()
        {
            _navAgent = agent.GetComponent<NavMeshAgent>();
            _animator = agent.GetComponent<Animator>();

            if (_navAgent == null || _animator == null)
            {
                EndAction(false);
                return;
            }

            _animator.SetBool(IsHoldingGunHash, true);
            _animator.SetBool(MoveForwardHash, false);
            _animator.CrossFade("Idle", 0.1f);
            _isMoving = false;
        }

        protected override void OnUpdate()
        {
            if (_navAgent == null || _animator == null)
            {
                EndAction(false);
                return;
            }

            Vector3 velocity = _navAgent.velocity;
            float speed = velocity.magnitude;
            bool moving = speed > MoveSpeedThreshold;

            if (moving != _isMoving)
            {
                _isMoving = moving;
                _animator.SetBool(MoveForwardHash, moving);
                _animator.CrossFade(moving ? "Walk With Rifle" : "Idle", 0.15f);
            }

            // 移动方向旋转（仅非战斗，战斗中由 BotAimAndShoot 控制）
            // 使用 GetVariable 避免变量不存在时产生错误日志
            var targetVar = blackboard.GetVariable(BotController.TargetEnemyVarName, typeof(GameObject));
            GameObject targetEnemy = targetVar != null ? targetVar.value as GameObject : null;
            if (targetEnemy == null && moving)
            {
                Vector3 moveDir = velocity.normalized;
                moveDir.y = 0f;
                if (moveDir != Vector3.zero)
                {
                    agent.rotation = Quaternion.LookRotation(moveDir);
                }
            }
        }

        protected override void OnPause() { }

        protected override void OnStop()
        {
            _navAgent = null;
            _animator = null;
        }
    }
}
