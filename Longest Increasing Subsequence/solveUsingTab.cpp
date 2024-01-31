int lengthOfLISUsingTab(vector<int> &nums)
{
    int n = nums.size();
    vector<vector<int>> dp(n + 4, vector<int>(n + 4, 0));

    for (int curr = n - 1; curr >= 0; curr--)
    {
        for (int prev = curr - 1; prev >= -1; prev--)
        {
            int include = 0;
            if (prev == -1 || nums[prev] < nums[curr])
            {
                include = 1 + dp[curr + 1][curr + 1];
            }
            int exclude = dp[curr + 1][prev + 1];

            int ans = max(include, exclude);
            dp[curr][prev + 1] = ans;
        }
    }
    return dp[0][0];
}

int lengthOfLIS(vector<int> &nums)
{
    int curr = 0;
    int prev = -1;

    // int ans =  lengthOfLISUsingRecursion(nums,curr,prev);

    int ans = lengthOfLISUsingTab(nums);
    return ans;
}