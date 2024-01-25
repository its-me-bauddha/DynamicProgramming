#include <iostream>
#include <vector>
using namespace std;
// index -> index of the element
int knapsack01SolveSO(int *weight, int *value, int n, int capacity)
{
    vector<int> prev(capacity + 1, 0);
    vector<int> curr(capacity + 1, 0);

    // base case observe
    for (int w = weight[0]; w <= capacity; w++)
    {
        if (weight[0] <= capacity)
        {
            prev[w] = value[0];
        }
        else
        {
            prev[w] = 0;
        }
    }

    for (int index = 1; index < n; index++)
    {
        for (int wt = 0; wt <= capacity; wt++)
        {
            int include = 0;
            if (weight[0] <= wt)
            {
                include = value[index] + prev[wt - weight[index]];
            }

            int exclude = prev[wt];

            curr[wt] = max(include, exclude);
        }
        // shift
        prev = curr;
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