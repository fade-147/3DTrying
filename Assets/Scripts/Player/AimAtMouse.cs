using UnityEngine;
using UnityEngine.Animations;
using Mirror;

public class AimAtMouse : MonoBehaviour
{
    [Header("瞄准设置")]
    public Transform aimTarget; // 准星空物体
    public Transform spine;     // 腰部/脊柱骨骼
    public float rotateSpeed = 10f;
    public float maxUpAngle = 30f;    // 向上最大弯度
    public float maxDownAngle = 30f;  // 向下最大弯度

    private Animator anim;
    private Vector3 mouseWorldPos;

    // 玩家角色脚本（获取死亡状态）
    private PlayerCharacter playerCharacter;
    // 网络身份组件
    private NetworkIdentity networkIdentity;

    void Start()
    {
        anim = GetComponent<Animator>();
        //获取组件
        networkIdentity = GetComponent<NetworkIdentity>();
        playerCharacter = GetComponent<PlayerCharacter>();
    }

    void LateUpdate()
    {

        // 只有本地玩家可以执行瞄准逻辑
        // 玩家死亡后禁用瞄准
        if (!networkIdentity.isLocalPlayer || (playerCharacter != null && playerCharacter.isDead))
        {
            return;
        }

        if (!spine || !aimTarget) return;

        // 鼠标转世界点
        Ray ray = Camera.main.ScreenPointToRay(Input.mousePosition);
        if (Physics.Raycast(ray, out RaycastHit hit))
        {
            mouseWorldPos = hit.point;
        }
        else
        {
            mouseWorldPos = ray.GetPoint(100);
        }

        // 让准星指向鼠标
        aimTarget.position = mouseWorldPos;

        // 计算腰部需要看向的方向
        Vector3 lookDir = mouseWorldPos - spine.position;
        Quaternion targetRot = Quaternion.LookRotation(lookDir);

        // 限制旋转角度（防止扭曲穿模）
        Quaternion limitedRot = Quaternion.RotateTowards(
            spine.rotation,
            targetRot,
            maxUpAngle
        );

        // 平滑旋转腰部
        spine.rotation = Quaternion.Lerp(
            spine.rotation,
            limitedRot,
            rotateSpeed * Time.deltaTime
        );
    }
}