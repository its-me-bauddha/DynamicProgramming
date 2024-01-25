#include <iostream>
#include <vector>
using namespace std;
// index -> index of the element
int knapsack01SolveSO(int *weight, int *value, int n, int capacity)
{

    vector<int> curr(capacity + 1, 0);

    // base case observe
    for (int w = weight[0]; w <= capacity; w++)
    {
        if (weight[0] <= capacity)
        {
            curr[w] = value[0];
        }
        else
        {
            curr[w] = 0;
        }
    }

    for (int index = 1; index < n; index++)
    {
        for (int wt = capacity; wt >= 0; wt--)
        {
            int include = 0;
            if (weight[0] <= wt)
            {
                include = value[index] + curr[wt - weight[index]];
            }

            int exclude = curr[wt];

            curr[wt] = max(include, exclude);
        }
    }
    return curr[capacity];
}

int main()
{
    int weight[] = {4, 5, 1};
    int value[] = {1, 2, 3};
    int n = 3;
    int capacity = 4;
    // create a 2d dp array

    int ans = knapsack01SolveSO(weight, value, n, capacity);
    cout << "Printing Ans : " << ans << endl;
}