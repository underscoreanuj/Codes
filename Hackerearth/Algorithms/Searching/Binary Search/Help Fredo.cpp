#include <bits/stdc++.h>

using namespace std;

#define ll long long int

auto speedup = []() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

int main()
{
    int n = 0;
    ll max_ele = INT_MIN;
    long double x = 0, prod = 0;

    cin >> n;

    for (int i = 0; i < n; ++i)
    {
        cin >> x;
        prod += log(x);
        max_ele = max(max_ele, (ll)x);
    }

    if (max_ele == 1)
    {
        cout << "2";
        return 0;
    }

    ll l = 1, r = max_ele, mid = 0, ans = 0;

    while (l <= r)
    {
        mid = l + ((r - l) >> 1);

        if ((long double)n * log((long double)mid) > prod)
        {
            ans = mid;
            r = mid - 1;
        }
        else
            l = mid + 1;
    }

    cout << ans;

    return 0;
}