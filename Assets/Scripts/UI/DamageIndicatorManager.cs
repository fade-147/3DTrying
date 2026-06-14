using UnityEngine;
using UnityEngine.UI;
using System.Collections.Generic;

/// <summary>
/// 受伤方向指示器管理器。
/// 在屏幕边缘显示指向伤害来源方向的红色箭头，CS:GO 风格。
/// 纯客户端 UI 组件，非 NetworkBehaviour。
/// 由 PlayerCharacter.TargetShowDamageDirection 触发。
/// </summary>
public class DamageIndicatorManager : MonoBehaviour
{
    [Header("视觉设置")]
    [Tooltip("方向箭头 Sprite（可在 Inspector 或 Resources/DamageArrow 设置）")]
    public Sprite indicatorSprite;

    [Tooltip("指示器颜色")]
    public Color indicatorColor = new Color(1f, 0.12f, 0.08f, 0.85f);

    [Tooltip("指示器大小（像素）")]
    public float indicatorSize = 72f;

    [Tooltip("距屏幕边缘的内缩距离（像素）")]
    public float edgeDistance = 80f;

    [Tooltip("淡出持续时间（秒）")]
    public float fadeDuration = 1.5f;

    [Tooltip("最大同时显示指示器数")]
    public int maxIndicators = 6;

    // 忽略距离摄像机 10cm 内的伤害源（避免方向计算不稳定）
    private const float MinDistanceSqr = 0.01f;

    // ——— 内部数据结构 ———

    private class Indicator
    {
        public Image image;
        public float elapsed;
        public Vector3 worldDirection; // 从玩家到攻击者的水平单位向量
    }

    private readonly Queue<Indicator> _pool = new Queue<Indicator>();
    private readonly List<Indicator> _active = new List<Indicator>();

    private Camera _cachedCamera;
    private RectTransform _canvasRect;

    // ——— Unity 生命周期 ———

    private void Awake()
    {
        Canvas canvas = GetComponentInParent<Canvas>();
        if (canvas != null)
            _canvasRect = canvas.GetComponent<RectTransform>();

        // 预热对象池
        for (int i = 0; i < maxIndicators; i++)
        {
            Indicator ind = CreateIndicator();
            ind.image.gameObject.SetActive(false);
            _pool.Enqueue(ind);
        }
    }

    private void Update()
    {
        // 每帧刷新摄像机引用（处理 1P/3P 切换）
        if (_cachedCamera == null || !_cachedCamera.isActiveAndEnabled)
            _cachedCamera = Camera.main;

        float dt = Time.deltaTime;

        for (int i = _active.Count - 1; i >= 0; i--)
        {
            Indicator ind = _active[i];
            ind.elapsed += dt;

            if (ind.elapsed >= fadeDuration)
            {
                // 淡出完成，回池
                ind.image.gameObject.SetActive(false);
                _pool.Enqueue(ind);
                _active.RemoveAt(i);
            }
            else
            {
                // 更新透明度
                float t = 1f - (ind.elapsed / fadeDuration);
                Color c = ind.image.color;
                c.a = Mathf.Lerp(0f, indicatorColor.a, t);
                ind.image.color = c;

                // 更新屏幕位置（摄像机可能旋转了）
                UpdateIndicatorPosition(ind);
            }
        }
    }

    // ——— 公开 API ———

    /// <summary>
    /// 显示一个指向 attackWorldPos 的方向指示器。
    /// 由 PlayerCharacter.TargetShowDamageDirection 调用。
    /// </summary>
    public void ShowIndicator(Vector3 attackerWorldPos)
    {
        if (_cachedCamera == null)
            _cachedCamera = Camera.main;
        if (_cachedCamera == null) return;

        Vector3 myPos = _cachedCamera.transform.position;
        Vector3 toAttacker = attackerWorldPos - myPos;
        toAttacker.y = 0f;

        if (toAttacker.sqrMagnitude < MinDistanceSqr) return;

        Vector3 worldDir = toAttacker.normalized;

        // 已有同方向指示器则重置计时（30° 范围内，cos ≈ 0.866）
        Indicator existing = TryReuseExisting(worldDir);
        if (existing != null) return;

        Indicator ind = GetOrCreateIndicator();
        ind.worldDirection = worldDir;
        ind.elapsed = 0f;
        ind.image.gameObject.SetActive(true);
        ind.image.color = indicatorColor;

        UpdateIndicatorPosition(ind);
        _active.Add(ind);
    }

    // ——— 内部方法 ———

    private void UpdateIndicatorPosition(Indicator ind)
    {
        if (_cachedCamera == null || _canvasRect == null) return;

        Vector3 camForward = _cachedCamera.transform.forward;
        camForward.y = 0f;
        camForward.Normalize();

        Vector3 camRight = _cachedCamera.transform.right;
        camRight.y = 0f;
        camRight.Normalize();

        float dotForward = Vector3.Dot(ind.worldDirection, camForward);
        float dotRight = Vector3.Dot(ind.worldDirection, camRight);

        if (Mathf.Approximately(dotForward, 0f) && Mathf.Approximately(dotRight, 0f)) return;

        Vector2 screenDir = new Vector2(dotRight, dotForward).normalized;

        RectTransform rt = ind.image.rectTransform;
        rt.anchoredPosition = GetEdgePosition(screenDir);

        // 旋转箭头使其指向伤害来源（箭头图片默认指向上方）
        float angle = Mathf.Atan2(screenDir.y, screenDir.x) * Mathf.Rad2Deg;
        rt.rotation = Quaternion.Euler(0f, 0f, angle - 90f);
    }

    /// <summary>
    /// 将屏幕方向映射到 Canvas 矩形边缘坐标。
    /// 使用矩形包围盒算法——找到从中心出发的射线与矩形的交点。
    /// </summary>
    private Vector2 GetEdgePosition(Vector2 dir)
    {
        float halfW = _canvasRect.rect.width * 0.5f - edgeDistance;
        float halfH = _canvasRect.rect.height * 0.5f - edgeDistance;

        if (halfW <= 0f) halfW = 1f;
        if (halfH <= 0f) halfH = 1f;

        // 与水平边相交
        if (Mathf.Abs(dir.x) * halfH > Mathf.Abs(dir.y) * halfW)
        {
            if (Mathf.Approximately(dir.x, 0f)) return Vector2.zero;
            float x = Mathf.Sign(dir.x) * halfW;
            float y = dir.y / Mathf.Abs(dir.x) * halfW;
            y = Mathf.Clamp(y, -halfH, halfH);
            return new Vector2(x, y);
        }
        // 与垂直边相交
        else if (!Mathf.Approximately(dir.y, 0f))
        {
            float y = Mathf.Sign(dir.y) * halfH;
            float x = dir.x / Mathf.Abs(dir.y) * halfH;
            x = Mathf.Clamp(x, -halfW, halfW);
            return new Vector2(x, y);
        }

        return Vector2.zero;
    }

    /// <summary>
    /// 检查是否已有方向相近（30°以内）的指示器，有则重置其计时器。
    /// </summary>
    private Indicator TryReuseExisting(Vector3 worldDir)
    {
        const float reuseThreshold = 0.866f; // cos(30°)
        for (int i = 0; i < _active.Count; i++)
        {
            if (Vector3.Dot(_active[i].worldDirection, worldDir) > reuseThreshold)
            {
                _active[i].elapsed = 0f;
                // 方向取平均，避免微小偏差累积
                _active[i].worldDirection = (_active[i].worldDirection + worldDir).normalized;
                return _active[i];
            }
        }
        return null;
    }

    private Indicator GetOrCreateIndicator()
    {
        if (_pool.Count > 0)
            return _pool.Dequeue();

        // 对象池耗尽——回收最旧的
        if (_active.Count > 0)
        {
            Indicator oldest = _active[0];
            _active.RemoveAt(0);
            return oldest;
        }

        // 极端情况：池为空且活跃列表也为空
        return CreateIndicator();
    }

    private Indicator CreateIndicator()
    {
        GameObject go = new GameObject("DamageIndicator");
        go.transform.SetParent(transform, false);

        RectTransform rt = go.AddComponent<RectTransform>();
        rt.sizeDelta = new Vector2(indicatorSize, indicatorSize);
        rt.anchorMin = new Vector2(0.5f, 0.5f);
        rt.anchorMax = new Vector2(0.5f, 0.5f);

        Image img = go.AddComponent<Image>();
        img.raycastTarget = false;
        if (indicatorSprite != null)
            img.sprite = indicatorSprite;

        return new Indicator { image = img };
    }
}
