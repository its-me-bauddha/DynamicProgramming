int spaceOptimizedSolution(vector<int> &nums, int n)
{

    int prev2 = 0;
    int prev1 = nums[0];
    // dp[i] -> depends on dp[i-1] and dp[i-2] so here the optimzation  is possible
    // using three varaible we can solve this problem

    int curr;
    for (int i = 1; i <= n; i++)
    {
        int temp = 0;
        if (i - 2 >= 0)
        {
            temp = prev2;
        }
        int include = temp + nums[i];
        int exclude = prev1;
        curr = max(include, exclude);
        prev2 = prev1;
        prev1 = curr;
    }

    return prev1;
}
int rob(vector<int> &nums)
{
    int n = nums.size() - 1;
    // 4. SPACE OPTIMIZATION
    return spaceOptimizedSolution(nums, n);
}