class Solution
{
public:
    int solveTab(vector<int> &coins, int amount)
    {
        // Step 1. create dp array & initialize
        // dp[i] -> minimum number of coins to create i amount,
        // that's why  we initialize dp with INT_MAX
        vector<int> dp(amount + 1, INT_MAX);

        // Step 2. observe base case from above
        dp[0] = 0;

        // Step 3. check the range and flow of top down approach & code accordingly
        for (int i = 1; i <= amount; i++)
        {
            for (int j = 0; j < coins.size(); j++)
            {
                if ((i - coins[j] >= 0) && dp[i - coins[j]] != INT_MAX)
                {
                    // replace/ change recursive calls of memoization by dp
                    int ans = dp[i - coins[j]];
                    dp[i] = min(dp[i], 1 + ans);
                }
            }
        }
        // In this problem dp[i] depends on  dp[i-coins[j]]
        // coins[j] -> contains variable amount so here
        //! SPACE OPTIMIZATION IS NOT POSSIBLE IN THIS PROBLEM

        return dp[amount];
    }
    int coinChange(vector<int> &coins, int amount)
    {

        // 3. BOTTOM UP APPROACH (Tabulation)

        int ans = solveTab(coins, amount);
        if (ans == INT_MAX)
            return -1;
        else
            return ans;
        s
    }
};