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

    private void OnCollisionEnter(Collision other)
    {
        // 仅服务端处理碰撞伤害
        if (!isServer) return;

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
            targetPlayer.TakeDamage(15f);
        }

        // 服务端销毁子弹
        NetworkServer.Destroy(gameObject);
    }
}