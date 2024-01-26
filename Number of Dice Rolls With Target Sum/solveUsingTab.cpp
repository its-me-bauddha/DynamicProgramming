int solveUsingTabulation(int n, int k, int target)
{
    vector<vector<int>> dp(n + 1, vector<int>(target + 1, 0));
    dp[0][0] = 1;

    for (int index = 1; index <= n; index++)
    {
        for (int t = 1; t <= target; t++)
        {
            long long int ans = 0;
            for (int i = 1; i <= k; i++)
            {
                long long int ansRec = 0;
                if (t - i >= 0)
                    ansRec = dp[index - 1][t - i];
                ansRec = ansRec % MOD;
                ans = ans % MOD;
                ans = (ans + ansRec) % MOD;
            }
            dp[index][t] = ans;
        }
    }
    return dp[n][target];
}
int numRollsToTarget(int n, int k, int target)
{

    return solveUsingTabulation(n, k, target);
}