#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long int t = 0, n = 0, a = 0, b = 0, cost1 = 0, cost2 = 0, x = 0, y = 0;
    cin >> t;

    while (t--)
    {
        cin >> n >> a >> b;
        x = n * b / (a + b);
        y = n - x;
        cost1 = a * x * x + b * y * y;
        ++x;
        --y;
        cost2 = a * x * x + b * y * y;

        cout << min(cost1, cost2) << "\n";
    }

    return 0;
}