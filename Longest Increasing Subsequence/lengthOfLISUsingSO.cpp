int lengthOfLISUsingSO(vector<int> &nums)
{
    int n = nums.size();
    vector<int> currRow(n + 1, 0);
    vector<int> nextRow(n + 1, 0);

    for (int curr = n - 1; curr >= 0; curr--)
    {
        for (int prev = curr - 1; prev >= -1; prev--)
        {
            int include = 0;
            if (prev == -1 || nums[prev] < nums[curr])
            {
                include = 1 + nextRow[curr + 1];
            }
            int exclude = nextRow[prev + 1];

            int ans = max(include, exclude);
            currRow[prev + 1] = ans;
        }

        // shift
        nextRow = currRow;
    }
    return nextRow[0];
}

int lengthOfLIS(vector<int> &nums)
{
    int curr = 0;
    int prev = -1;

    // int ans =  lengthOfLISUsingRecursion(nums,curr,prev);

    int ans = lengthOfLISUsingSO(nums);
    return ans;
}