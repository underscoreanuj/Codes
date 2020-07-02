#include <bits/stdc++.h>

using namespace std;

#define ll long long int

bool isValid(vector<ll> &a, ll window, ll limit)
{
    ll sum = 0;
    for (int i = 0; i < window; ++i)
    {
        sum += a[i];
        if (sum > limit)
            return false;
    }

    for (int i = window; i < a.size(); ++i)
    {
        sum -= a[i - window];
        sum += a[i];
        if (sum > limit)
            return false;
    }

    return true;
}

int main()
{
    ll n = 0, x = 0;
    cin >> n >> x;
    vector<ll> a(n, 0);
    for (int i = 0; i < n; ++i)
        cin >> a[i];

    ll l = 1, r = n, mid = 0, ans = 0;

    while (l <= r)
    {
        mid = l + ((r - l) >> 1);

        if (isValid(a, mid, x))
        {
            ans = mid;
            l = mid + 1;
        }
        else
            r = mid - 1;
    }

    cout << ans;

    return 0;
}

auto speedup = []() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();