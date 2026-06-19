using System.Collections;
using UnityEngine;

/// <summary>
/// 场景切换过渡动画控制器。
/// 运行时由 MyYooAsset 通过 AddComponent 动态挂载。
/// 使用 CrossFade + overlap 策略：前一个动画结束前 0.2s 就开始下一个的渐变混合，
/// 消除动画间隙。
/// </summary>
public class LoadingTransitionController : MonoBehaviour
{
    public static LoadingTransitionController Instance { get; private set; }

    /// <summary>前一个动画结束前多少秒启动下一个 CrossFade</summary>
    private const float OVERLAP = 0.2f;
    /// <summary>CrossFade 过渡混合时长</summary>
    private const float CROSSFADE = 0.15f;

    private static readonly int StateFadeIn  = Animator.StringToHash("FadeAnimation");
    private static readonly int[] StateMiddles =
    {
        Animator.StringToHash("Fade1Animation"),
        Animator.StringToHash("Fade2Animation"),
        Animator.StringToHash("Fade3Animation"),
        Animator.StringToHash("Fade4Animation"),
        Animator.StringToHash("Fade5Animation"),
    };
    private static readonly int StateFadeOut = Animator.StringToHash("FadeOutAnimation");

    private Animator _animator;
    private bool _isLoadComplete;
    private int _lastMiddleIndex = -1;
    private Coroutine _animationCoroutine;

    public bool IsActive { get; private set; }

    private void Awake()
    {
        if (Instance == null)
        {
            Instance = this;
            DontDestroyOnLoad(gameObject);
            _animator = GetComponentInChildren<Animator>();
            gameObject.SetActive(false);
        }
        else
        {
            Destroy(gameObject);
        }
    }

    public void Show()
    {
        gameObject.SetActive(true);
        if (_animationCoroutine != null)
            StopCoroutine(_animationCoroutine);
        _animationCoroutine = StartCoroutine(AnimationSequence());
    }

    public void NotifyLoadComplete() => _isLoadComplete = true;

    public void Hide()
    {
        if (_animationCoroutine != null)
        {
            StopCoroutine(_animationCoroutine);
            _animationCoroutine = null;
        }
        gameObject.SetActive(false);
        IsActive = false;
    }

    /// <summary>
    /// 获取 CrossFade 目标状态的 clip 长度。
    /// CrossFade 过渡期间用 GetNextAnimatorStateInfo，否则用 GetCurrentAnimatorStateInfo。
    /// </summary>
    private float TargetClipLength()
    {
        if (_animator.IsInTransition(0))
        {
            var next = _animator.GetNextAnimatorStateInfo(0);
            if (next.length > 0f) return next.length;
        }
        return _animator.GetCurrentAnimatorStateInfo(0).length;
    }

    private IEnumerator AnimationSequence()
    {
        IsActive = true;
        _isLoadComplete = false;
        _lastMiddleIndex = -1;

        // 1. 渐入
        _animator.CrossFade(StateFadeIn, CROSSFADE, 0);
        yield return null;
        yield return new WaitForSeconds(TargetClipLength() - OVERLAP);

        // 2. 中间动画循环
        while (!_isLoadComplete)
        {
            int idx = PickRandomMiddle();
            _animator.CrossFade(StateMiddles[idx], CROSSFADE, 0);
            yield return null;
            yield return new WaitForSeconds(TargetClipLength() - OVERLAP);
        }

        // 3. 渐出
        _animator.CrossFade(StateFadeOut, CROSSFADE, 0);
        yield return null;
        yield return new WaitForSeconds(TargetClipLength() - OVERLAP);

        // 4. 收尾
        gameObject.SetActive(false);
        IsActive = false;
        _animationCoroutine = null;
    }

    private int PickRandomMiddle()
    {
        if (StateMiddles.Length == 1) return 0;
        int idx;
        do { idx = Random.Range(0, StateMiddles.Length); }
        while (idx == _lastMiddleIndex);
        _lastMiddleIndex = idx;
        return idx;
    }

    private void OnDestroy()
    {
        if (Instance == this) Instance = null;
    }
}
