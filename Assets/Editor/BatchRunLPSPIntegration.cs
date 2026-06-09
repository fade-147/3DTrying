using UnityEngine;
using UnityEditor;

/// <summary>
/// Batch-mode entry point: runs all 3 LPSP integration tools non-interactively.
/// Called via: unity -batchmode -quit -projectPath ... -executeMethod BatchRunLPSPIntegration.RunAll
/// </summary>
public class BatchRunLPSPIntegration
{
    public static void RunAll()
    {
        Debug.Log("===== [Batch] STEP 1/3: FixImportedLPSPPrefab =====");
        FixImportedLPSPPrefab.RunAllNonInteractive();

        Debug.Log("===== [Batch] STEP 2/3: CleanupAndIntegrate =====");
        CleanupAndIntegrate.Run();

        Debug.Log("===== [Batch] STEP 3/3: FinalizePlayer2View =====");
        FinalizePlayer2View.Run();

        Debug.Log("===== [Batch] ALL 3 DONE =====");
    }
}
