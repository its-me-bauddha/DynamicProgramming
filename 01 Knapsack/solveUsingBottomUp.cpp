#include <iostream>
#include <vector>
using namespace std;
// index -> index of the element
int knapsack01SolveTab(int *weight, int *value, int n, int capacity)
{
    vector<vector<int>> dp(n, vector<int>(capacity + 1, -1));

    // base case observe
    for (int w = weight[0]; w <= capacity; w++)
    {
        if (weight[0] <= capacity)
        {
            dp[0][w] = value[0];
        }
        else
        {
            dp[0][w] = 0;
        }
    }

    for (int index = 1; index < n; index++)
    {
        for (int wt = 0; wt <= capacity; wt++)
        {
            int include = 0;
            if (weight[0] <= wt)
            {
                include = value[index] + dp[index - 1][wt - weight[index]];
            }

            int exclude = dp[index - 1][wt];

            dp[index][wt] = max(include, exclude);
        }
    }
    return dp[n - 1][capacity];
}

int main()
{
    int weight[] = {4, 5, 1};
    int value[] = {1, 2, 3};
    int n = 3;
    int capacity = 4;
    // create a 2d dp array

    int ans = knapsack01SolveTab(weight, value, n, capacity);
    cout << "Printing Ans : " << ans << endl;
}