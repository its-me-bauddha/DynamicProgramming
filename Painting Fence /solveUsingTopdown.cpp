#include <iostream>
using namespace std;

int solveUsingMem(int n, int k, vector<int> &dp)
{

    if (n == 1)
    {
        return k;
    }
    if (n == 2)
    {
        return (k + k * (k - 1));
    }
    if (dp[n] != -1)
    {
        return dp[n];
    }
    dp[n] = (solveUsingMem(n - 2, k, dp) + solveUsingMem(n - 1, k, dp)) * (k - 1);
    return dp[n];
}
int main()
{
    int n = 4;
    int k = 3;
    vector<int> dp(n + 1, -1);
    int ans = solveUsingMem(n, k, dp);

    cout << "Printing Ans -> " << ans << endl;
}