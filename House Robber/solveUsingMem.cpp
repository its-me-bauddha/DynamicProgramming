int solveUsingMem(vector<int>& nums,int n ,vector<int>& dp){
        // n -> represents the index of current house
        // base case
        // 1. no house exists
        if(n < 0) return 0;
        // 2. only one house exists
        if(n == 0) return nums[0];

        // step 3 check ans already exists  or not !
        if(dp[n] != -1) return dp[n];

        int include = solveUsingMem(nums,n-2,dp) + nums[n];// include index
        int exclude =  solveUsingMem(nums,n-1,dp) ; // exclude index

        // step 2 :  store the ans in dp array 
        dp[n] =  max(include,exclude);
        return dp[n];
}

int rob(vector<int>& nums) {
        // 2. TOP DOWN APPROACH (MEMOIZATION)
        // step 1 create dp array 
         int n = nums.size()-1;
        vector<int> dp(n+1,-1);
        return solveUsingMem(nums,n,dp);
       
    }