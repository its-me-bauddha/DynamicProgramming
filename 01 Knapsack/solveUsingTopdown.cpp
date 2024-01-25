#include <iostream>
#include <vector>
using namespace std;
// index -> index of the element
int knapsack01SolveMemo(int *weight, int *value, int index, int capacity, vector<vector<int>> &dp)
{
    // base case -> only one element is present
    if (index == 0)
    {
        if (weight[0] <= capacity)
        {
            return value[0];
        }
        else
        {
            return 0;
        }
    }
    if (dp[index][capacity] != -1)
    {
        return dp[index][capacity];
    }
    int include = 0;
    if (weight[0] <= capacity)
    {
        include = value[index] + knapsack01SolveMemo(weight, value, index - 1, capacity - weight[index], dp);
    }

    int exclude = knapsack01SolveMemo(weight, value, index - 1, capacity, dp);

    dp[index][capacity] = max(include, exclude);
    return dp[index][capacity];
}

int main()
{
    int weight[] = {4, 5, 1};
    int value[] = {1, 2, 3};
    int n = 3;
    int capacity = 4;
    // create a 2d dp array
    vector<vector<int>> dp(n, vector<int>(capacity + 1, -1));
    int ans = knapsack01SolveMemo(weight, value, n - 1, capacity, dp);
    cout << "Printing Ans : " << ans << endl;
}