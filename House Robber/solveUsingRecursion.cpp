class Solution {
public:
    
    int solveUsingRecursion(vector<int>&nums,int n){
        // n -> represents the index of current house
        // base case
        // 1. no house exists
        if(n < 0) return 0;
        // 2. only one house exists
        if(n == 1) return nums[0];


        // include index
        int include = solveUsingRecursion(nums,n-2) + nums[n];

        // exclude index
        int exclude =  solveUsingRecursion(nums,n-1);

        return max(include,exclude);

    }
    int rob(vector<int>& nums) {
        // 1. RECURSION SOLUTION
        int n = nums.size()-1;
        return solveUsingRecursion(nums,n);
    }
};