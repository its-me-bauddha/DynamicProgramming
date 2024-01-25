#include <iostream>
using namespace std;
int solveUsingRecursion(int n, int k)
{

    if (n == 1)
    {
        return k;
    }
    if (n == 2)
    {
        return (k + k * (k - 1));
    }

    int ans = (solveUsingRecursion(n - 2, k) + solveUsingRecursion(n - 1, k)) * (k - 1);
    return ans;
}
int solveUsingMem(int n ,int k ,vector<int>&dp){

    if (n == 1)
    {
        return k;
    }
    if (n == 2)
    {
        return (k + k * (k - 1));
    }
    if(dp[n] !=-1){
        return dp[n];
    }
    dp[n] = (solveUsingMem(n - 2, k,dp) + solveUsingMem(n - 1, k,dp)) * (k - 1);
    return dp[n];
}
int main()
{
    int n = 4;
    int k = 3;

    int ans = solveUsingRecursion(n, k);
    
    cout << "Printing Ans -> " << ans << endl;
}