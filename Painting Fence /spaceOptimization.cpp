#include <iostream>
using namespace std;

int spaceOptimisation(int n, int k)
{

    int prev1 = k;
    int prev2 = (k + k * (k - 1));

    int curr;
    for (int i = 3; i <= n; i++)
    {
        curr = (prev1 + prev2) * (k - 1);
        // shifting
        prev1 = prev2;
        prev2 = curr;
    }
    return curr;
}
int main()
{
    int n = 4;
    int k = 3;
    int ans = spaceOptimisation(n, k);

    cout << "Printing Ans -> " << ans << endl;
}