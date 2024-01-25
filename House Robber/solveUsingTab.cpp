int solveUsingTab(vector<int>&nums,int n){
        // step 1 create dp array
        vector<int> dp(n+1,0);

        // step 2 check base case and store it in dp array
        dp[0] = nums[0];

        // step 3 observe top down approach
        for(int i =1;i<=n;i++){
            int temp = 0 ;
            if(i-2 >= 0){
                temp = dp[i-2];
            }
            int include = temp + nums[i];
            int exclude = dp[i-1];
            dp[i] = max(include ,exclude);
        }

        return dp[n];

    }
    int rob(vector<int>& nums) {
        
        int n = nums.size()-1;
        // 3 . BOTTOM UP APPROACH (Tabulation method)

        return solveUsingTab(nums,n);
       
    }