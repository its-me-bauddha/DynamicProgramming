int solveOptimal(vector<int> &nums)
{
    if (nums.size() == 0)
        return 0;

    vector<int> ans;
    ans.push_back(nums[0]);

    for (int i = 1; i < nums.size(); i++)
    {
        if (ans.back() < nums[i])
        {
            ans.push_back(nums[i]);
        }
        else
        {
            // overwrite
            // find the index of just large num
            int index = lower_bound(ans.begin(), ans.end(), nums[i]) - ans.begin();
            ans[index] = nums[i];
        }
    }
    return ans.size();
}

int lengthOfLIS(vector<int> &nums)
{
    // int curr = 0;
    // int prev = -1;

    // // int ans =  lengthOfLISUsingRecursion(nums,curr,prev);

    //   int ans =  lengthOfLISUsingSO(nums);
    // return ans;

    return solveOptimal(nums);
}