#include <bits/stdc++.h>

using namespace std;

#define ll long long int

auto speedup = []() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

ll countPairs(vector<ll> &a, ll diff)
{
    ll count = 0, l = 0;
    for (ll r = 1; r < a.size(); ++r)
    {
        while (a[r] - a[l] > diff)
            ++l;
        count += r - l;
    }
    return count;
}

int main()
{
    ll n = 0, k = 0, val;
    cin >> n >> k;
    vector<ll> a(n, 0);

    for (ll i = 0; i < n; ++i)
        cin >> a[i];

    sort(a.begin(), a.end());

    ll l = 0, r = a[a.size() - 1] - a[0], mid = 0;

    while (l < r)
    {
        mid = l + ((r - l) >> 1);

        if (countPairs(a, mid) >= k)
            r = mid;
        else
            l = mid + 1;
    }

    cout << l;

    return 0;
}