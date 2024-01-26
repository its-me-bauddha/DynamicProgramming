bool solveSpaceOpt(vector<int> &nums, int target)
{
    int n = nums.size();

    vector<bool> curr(target + 1, 0);
    vector<bool> next(target + 1, 0);

    curr[0] = 1;
    next[0] = 1;

    for (int index = n - 1; index >= 0; index--)
    {
        for (int t = 1; t <= target; t++)
        {
            bool include = 0;
            if (t - nums[index] >= 0)
                include = next[t - nums[index]];

            bool exclude = next[t];

            curr[t] = (include || exclude);
        }
        // shift
        next = curr;
    }
    return curr[target];
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

    bool ans = solveSpaceOpt(nums, target);
    return ans;
}