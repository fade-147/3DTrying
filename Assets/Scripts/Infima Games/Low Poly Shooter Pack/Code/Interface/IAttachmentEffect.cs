using System;
using System.Collections.Generic;
using UnityEngine;

namespace InfimaGames.LowPolyShooterPack
{
    /// <summary>
    /// 配件效果统一接口。所有配件（Scope/Muzzle/Laser/Grip/Magazine）实现此接口，
    /// 供 Weapon.Fire() 和 PlayerCombat 读取效果叠加。
    /// </summary>
    public interface IAttachmentEffect
    {
        /// <summary>后坐力减少百分比（0~1，0=无效果，0.1=减少10%）</summary>
        float RecoilReduction { get; }

        /// <summary>散布减少百分比（0~1）</summary>
        float SpreadReduction { get; }

        /// <summary>摇摆减少百分比（0~1）</summary>
        float SwayReduction { get; }

        /// <summary>是否消音（隐藏伤害方向指示器）</summary>
        bool SuppressSound { get; }

        /// <summary>弹药容量倍率（1.0=不变，1.2=+20%）</summary>
        float AmmoCapacityMultiplier { get; }

        /// <summary>腰射散布减少百分比（0~1）</summary>
        float HipfireSpreadReduction { get; }
    }
}
