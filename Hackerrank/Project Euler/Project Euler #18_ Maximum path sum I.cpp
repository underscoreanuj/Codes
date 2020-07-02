#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int getMaxPathSum(vector<vector<int>> &a)
{
    int n = a.size();

    for (int i = n - 2; i >= 0; --i)
    {
        for (int j = 0; j <= i; ++j)
        {
            a[i][j] += max(a[i + 1][j], a[i + 1][j + 1]);
        }
    }

    return a[0][0];
}

int main()
{
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int t = 0, n = 0, x = 0;
    cin >> t;

    while (t--)
    {
        cin >> n;
        vector<vector<int>> a(n);

        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j <= i; ++j)
            {
                cin >> x;
                a[i].push_back(x);
            }
        }

        cout << getMaxPathSum(a) << "\n";
    }
    return 0;
}
