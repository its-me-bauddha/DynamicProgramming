class Solution
{
public:
    bool solveUsingRecursion(vector<int> &nums, int target, int index)
    {
        // base case
        if (target == 0)
            return 1;
        if (index >= nums.size() || target < 0)
            return 0;

        bool include = solveUsingRecursion(nums, target - nums[index], index + 1);
        bool exclude = solveUsingRecursion(nums, target, index + 1);

        return include || exclude;
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

        bool ans = solveUsingRecursion(nums, target, index);
        return ans;
    }
};