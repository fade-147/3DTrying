using UnityEngine;
using System.Collections;
using System.Collections.Generic;

using Mirror;

// 联机修改：继承NetworkBehaviour
public class Bullet : NetworkBehaviour
{
    public GameObject HitEffect;
    public float BulletLifeTime = 2f;
    // 子弹归属者，防止自伤
    public NetworkIdentity ownerNetIdentity;

    // 服务端定时销毁子弹
    public override void OnStartServer()
    {
        base.OnStartServer();
        Destroy(gameObject, BulletLifeTime);
    }

    /// <summary>
    /// 服务端调用：忽略子弹与所有同队伍角色的碰撞，使子弹穿透队友。
    /// 需在 NetworkServer.Spawn 之后、子弹开始移动之前调用。
    /// </summary>
    [Server]
    public void SetupTeammateIgnore()
    {
        if (ownerNetIdentity == null) return;

        int shooterTeam = BotController.GetTeamId(ownerNetIdentity.GetComponent<PlayerCharacter>());
        if (shooterTeam < 0) return;

        Collider myCollider = GetComponent<Collider>();
        if (myCollider == null) return;

        PlayerCharacter[] allChars = FindObjectsByType<PlayerCharacter>(FindObjectsSortMode.None);
        foreach (PlayerCharacter pc in allChars)
        {
            if (BotController.GetTeamId(pc) != shooterTeam) continue;

            // 忽略同队的所有 Collider（含 CharacterController 和骨骼胶囊体）
            foreach (Collider c in pc.GetComponents<Collider>())
                Physics.IgnoreCollision(myCollider, c);
            foreach (Collider c in pc.GetComponentsInChildren<Collider>())
                Physics.IgnoreCollision(myCollider, c);
        }
    }

    private void OnCollisionEnter(Collision other)
    {
        // 仅服务端处理碰撞伤害
        if (!isServer) return;

        // 子弹互撞忽略——不生成特效、不销毁
        if (other.gameObject.GetComponent<Bullet>() != null)
            return;

        // 生成命中特效
        if (HitEffect != null)
        {
            var hitFX = Instantiate(HitEffect, transform.position, Quaternion.LookRotation(other.contacts[0].normal));
            // 网络生成特效
            NetworkServer.Spawn(hitFX);
            Destroy(hitFX, 1f);
        }

        // 防止击中自己，服务端扣血（GetComponentInParent 兼容骨骼碰撞体）
        var targetPlayer = other.gameObject.GetComponentInParent<PlayerCharacter>();
        if (targetPlayer != null && targetPlayer.netIdentity != ownerNetIdentity)
        {
            targetPlayer.TakeDamage(15f, ownerNetIdentity);
        }

        // 服务端销毁子弹
        NetworkServer.Destroy(gameObject);
    }
}
