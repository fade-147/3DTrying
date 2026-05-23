using NodeCanvas.Framework;
using ParadoxNotion.Design;
using UnityEngine;
using UnityEngine.AI;

namespace NodeCanvas.Tasks.Actions
{
    /// <summary>
    /// 每帧同步 NavMeshAgent 速度到 Animator 参数（Speed, MoveForward, IsHoldingGun）。
    /// 多帧任务，持续运行以保持动画同步。
    /// </summary>
    [Category("Bot")]
    [Description("Continuously sync NavMeshAgent velocity to Animator parameters")]
    public class BotUpdateAnim : ActionTask<Transform>
    {
        private NavMeshAgent _navAgent;
        private Animator _animator;

        private static readonly int SpeedHash = Animator.StringToHash("Speed");
        private static readonly int MoveForwardHash = Animator.StringToHash("MoveForward");
        private static readonly int IsHoldingGunHash = Animator.StringToHash("IsHoldingGun");
        private static readonly int MoveLeftHash = Animator.StringToHash("MoveLeft");
        private static readonly int MoveRightHash = Animator.StringToHash("MoveRight");
        private static readonly int MoveBackHash = Animator.StringToHash("MoveBack");

        protected override void OnExecute()
        {
            _navAgent = agent.GetComponent<NavMeshAgent>();
            _animator = agent.GetComponent<Animator>();

            if (_navAgent == null || _animator == null)
            {
                EndAction(false);
                return;
            }
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

            // Speed 参数控制移动混合树
            _animator.SetFloat(SpeedHash, speed);

            // 方向参数
            Vector3 localVelocity = agent.InverseTransformDirection(velocity);

            _animator.SetBool(MoveForwardHash, localVelocity.z > 0.1f);
            _animator.SetBool(MoveLeftHash, localVelocity.x < -0.1f);
            _animator.SetBool(MoveRightHash, localVelocity.x > 0.1f);
            _animator.SetBool(MoveBackHash, localVelocity.z < -0.1f);

            // Bot 始终持枪
            _animator.SetBool(IsHoldingGunHash, true);
        }

        protected override void OnPause() { }

        protected override void OnStop()
        {
            _navAgent = null;
            _animator = null;
        }
    }
}
