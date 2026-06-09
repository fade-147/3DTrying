using UnityEngine;

namespace InfimaGames.LowPolyShooterPack
{
    /// <summary>
    /// Bridges LPSP MovementBehaviour queries to the ThirdPersonController physics system.
    /// LPSP Character.cs calls GetComponent&lt;MovementBehaviour&gt;() to read movement state;
    /// this component answers from ThirdPersonController instead of running its own physics.
    /// </summary>
    public class ThirdPersonMovementBridge : MovementBehaviour
    {
        #region FIELDS

        private StarterAssets.ThirdPersonController _thirdPersonController;
        private CharacterController _characterController;

        [Header("Walking Multipliers (mirrors LPSP Movement defaults)")]
        [SerializeField, Range(0f, 1f)]
        private float walkingMultiplierForward = 1.0f;

        [SerializeField, Range(0f, 1f)]
        private float walkingMultiplierSideways = 1.0f;

        [SerializeField, Range(0f, 1f)]
        private float walkingMultiplierBackwards = 1.0f;

        #endregion

        #region UNITY

        protected override void Awake()
        {
            _thirdPersonController = GetComponent<StarterAssets.ThirdPersonController>();
            _characterController = GetComponent<CharacterController>();
        }

        #endregion

        #region GETTERS (MovementBehaviour)

        public override float GetLastJumpTime()
        {
            // TPC does not track last jump time separately; return 0 to avoid blocking downstream.
            return 0f;
        }

        public override float GetMultiplierForward() => walkingMultiplierForward;
        public override float GetMultiplierSideways() => walkingMultiplierSideways;
        public override float GetMultiplierBackwards() => walkingMultiplierBackwards;

        public override Vector3 GetVelocity()
        {
            if (_characterController != null)
                return _characterController.velocity;
            return Vector3.zero;
        }

        public override bool IsGrounded()
        {
            if (_thirdPersonController != null)
                return _thirdPersonController.Grounded;
            return false;
        }

        public override bool WasGrounded()
        {
            // TPC does not expose previous-frame grounded; proxy via current.
            return IsGrounded();
        }

        public override bool IsJumping()
        {
            // TPC does not expose a jump flag; grounded + upward velocity is a rough proxy.
            if (_thirdPersonController != null && _characterController != null)
                return !_thirdPersonController.Grounded && _characterController.velocity.y > 0f;
            return false;
        }

        public override bool CanCrouch(bool newCrouching)
        {
            // Crouch not supported yet in TPC bridge.
            return false;
        }

        public override bool IsCrouching()
        {
            return false;
        }

        #endregion

        #region METHODS (MovementBehaviour)

        /// <summary>
        /// Triggers a jump via ThirdPersonController.TriggerJump().
        /// </summary>
        public override void Jump()
        {
            if (_thirdPersonController != null)
                _thirdPersonController.TriggerJump();
        }

        public override void Crouch(bool crouching)
        {
            // Not supported yet.
        }

        public override void TryCrouch(bool value)
        {
            // Not supported yet.
        }

        public override void TryToggleCrouch()
        {
            // Not supported yet.
        }

        #endregion
    }
}
