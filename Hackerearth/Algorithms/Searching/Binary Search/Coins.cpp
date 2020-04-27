#include <bits/stdc++.h>

using namespace std;

#define ll long long int

int main()
{
    int n = 0, x = 0;
    cin >> n;

    vector<ll> countSum(100000, 0);
    int max_ele = INT_MIN;
    int min_ele = INT_MAX;

    for (int i = 0; i < n; ++i)
    {
        cin >> x;
        countSum[x] += x;
        max_ele = max(max_ele, x);
        min_ele = min(min_ele, x);
    }

    if (min_ele == max_ele)
    {
        cout << "NO\n";
        return 0;
    }

    for (int i = min_ele + 1; i <= max_ele; ++i)
        countSum[i] += countSum[i - 1];

    int l = min_ele, r = max_ele, mid = 0;
    bool flag = true;

    while (l <= r)
    {
        mid = l + ((r - l) >> 1);

        if (countSum[mid - 1] == (countSum[max_ele] - countSum[mid]))
        {
            cout << "YES\n";
            flag = false;
            break;
        }
        else if (countSum[mid - 1] < (countSum[max_ele] - countSum[mid]))
        {
            l = mid + 1;
        }
        else
            r = mid - 1;
    }

    if (flag)
        cout << "NO\n";

    return 0;
}