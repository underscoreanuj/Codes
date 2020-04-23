#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long int n = 0, x = 0, count = 0, max_sum = 0, max_ele = INT_MIN;
    cin >> n;

    for (int i = 0; i < n; ++i)
    {
        cin >> x;
        max_ele = max(max_ele, x);
        if (x >= 0)
        {
            ++count;
            max_sum += x;
        }
    }

    if (max_ele < 0)
    {
        cout << max_ele << " 1";
        return 0;
    }

    cout << max_sum << " " << count;

    return 0;
}