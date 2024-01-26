bool solveUsingTab(vector<int> &nums, int target)
{
    int n = nums.size();
    vector<vector<int>> dp(n + 1, vector<int>(target + 1, 0));

    for (int i = 0; i < n; i++)
    {
        dp[i][0] = 1;
    }

    for (int index = n - 1; index >= 0; index--)
    {
        for (int t = 1; t <= target; t++)
        {
            bool include = 0;
            if (t - nums[index] >= 0)
                include = dp[index + 1][t - nums[index]];
            bool exclude = dp[index + 1][t];
            dp[index][t] = include || exclude;
        }
    }
    return dp[0][target];
}
bool canPartition(vector<int> &nums)
{
    int sum = 0;
    for (auto i : nums)
    {
        sum += i;
    }
    // sum -> odd yha par galti karugaa
    if (sum & 1)
        return false;
    int target = sum / 2;
    int index = 0;
    bool ans = solveUsingTab(nums, target);
    return ans;
}