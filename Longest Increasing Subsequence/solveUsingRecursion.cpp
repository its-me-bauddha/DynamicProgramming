class Solution
{
public:
    int lengthOfLISUsingRecursion(vector<int> &nums, int curr, int prev)
    {
        if (curr >= nums.size())
            return 0;

        int include = 0;
        int exclude = 0;
        if (prev == -1 || nums[prev] < nums[curr])
        {
            include = 1 + lengthOfLISUsingRecursion(nums, curr + 1, curr);
        }
        exclude = lengthOfLISUsingRecursion(nums, curr + 1, prev);

        return max(include, exclude);
    }
    int lengthOfLIS(vector<int> &nums)
    {
        int curr = 0;
        int prev = -1;

        int ans = lengthOfLISUsingRecursion(nums, curr, prev);
        return ans;
    }
};