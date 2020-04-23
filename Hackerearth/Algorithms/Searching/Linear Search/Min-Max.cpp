#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, max_ele = INT_MIN, min_ele = INT_MAX, sum = 0, x = 0;
    cin >> n;

    for (int i = 0; i < n; ++i)
    {
        cin >> x;
        sum += x;
        max_ele = max(max_ele, x);
        min_ele = min(min_ele, x);
    }

    cout << (sum - max_ele) << " " << (sum - min_ele);

    return 0;
}