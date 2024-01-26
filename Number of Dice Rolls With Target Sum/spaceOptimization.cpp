int solveUsingTabulationSO(int n, int k, int target)
{
    vector<vector<int>> dp(n + 1, vector<int>(target + 1, 0));

    vector<int> prev(target + 1, 0);
    vector<int> curr(target + 1, 0);
    prev[0] = 1;

    for (int index = 1; index <= n; index++)
    {
        for (int t = 1; t <= target; t++)
        {
            long long int ans = 0;
            for (int i = 1; i <= k; i++)
            {
                long long int ansRec = 0;
                if (t - i >= 0)
                    ansRec = prev[t - i];
                ansRec = ansRec % MOD;
                ans = ans % MOD;
                ans = (ans + ansRec) % MOD;
            }
            curr[t] = ans;
        }
        // shift
        prev = curr;
    }
    return curr[target];
}

int numRollsToTarget(int n, int k, int target)
{

    return solveUsingTabulationSO(n, k, target);
}