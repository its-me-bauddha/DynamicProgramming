#include <iostream>
using namespace std;
// index -> index of the element
int knapsack01RecursiveSolve(int *weight, int *value, int index, int capacity)
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
    int include = 0;
    if (weight[0] <= capacity)
    {
        include = value[index] + knapsack01RecursiveSolve(weight, value, index - 1, capacity - weight[index]);
    }

    int exclude = knapsack01RecursiveSolve(weight, value, index - 1, capacity);

    return max(include, exclude);
}

int main()
{
    int weight[] = {4, 5, 1};
    int value[] = {1, 2, 3};
    int n = 3;
    int capacity = 4;

    int ans = knapsack01RecursiveSolve(weight, value, n - 1, capacity);
    cout << "Printing Ans : " << ans << endl;
}