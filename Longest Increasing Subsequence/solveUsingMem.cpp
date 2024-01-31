int lengthOfLISUsingMem(vector<int> &nums, int curr, int prev, vector<vector<int>> &dp)
{
    if (curr >= nums.size())
        return 0;

    int include = 0;

    if (dp[curr][prev + 1] != -1)
        return dp[curr][prev + 1];
    if (prev == -1 || nums[prev] < nums[curr])
    {
        include = 1 + lengthOfLISUsingMem(nums, curr + 1, curr, dp);
    }
    int exclude = lengthOfLISUsingMem(nums, curr + 1, prev, dp);

    int ans = max(include, exclude);
    dp[curr][prev + 1] = ans;
    return dp[curr][prev + 1];
}

int lengthOfLIS(vector<int> &nums)
{
    int curr = 0;
    int prev = -1;

    // int ans =  lengthOfLISUsingRecursion(nums,curr,prev);
    vector<vector<int>> dp(nums.size(), vector<int>(nums.size() + 1, -1));
    int ans = lengthOfLISUsingMem(nums, curr, prev, dp);
    return ans;
}