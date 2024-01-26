bool solveUsingMem(vector<int> &nums, vector<vector<int>> &dp, int target, int index)
{
    // base case
    if (target == 0)
        return 1;
    if (index >= nums.size() || target < 0)
        return 0;
    if (dp[index][target] != -1)
    {
        return dp[index][target];
    }

    bool include = solveUsingMem(nums, dp, target - nums[index], index + 1);
    bool exclude = solveUsingMem(nums, dp, target, index + 1);

    dp[index][target] = include || exclude;
    return dp[index][target];
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

       int n = nums.size();
    vector<vector<int>> dp(n, vector<int>(target + 1, -1));
    bool ans = solveUsingMem(nums, dp, target, index);
    return ans;
}