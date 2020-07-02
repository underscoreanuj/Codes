#include <bits/stdc++.h>

using namespace std;

#define ll long long int

auto speedup = []() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

ll getValue(vector<ll> &A, ll y, ll k)
{
    ll s = 0;
    for (ll i = 0; i < A.size(); ++i)
    {
        s += max(A[i] - y * (i + 1), (ll)0);
    }

    return s;
}

int main()
{
    int t = 0, n = 0;
    ll k = 0;
    cin >> t;
    while (t--)
    {
        cin >> n >> k;

        vector<ll> A(n, 0);
        for (int i = 0; i < n; ++i)
            cin >> A[i];

        ll l = 0, r = 1e12, mid = 0;
        ll s = 0;
        ll ans = 0, val = 0;

        while (l <= r)
        {
            mid = l + ((r - l) >> 1);
            s = getValue(A, mid, k);

            if (s >= k)
            {
                ans = mid;
                val = s;
                l = mid + 1;
            }
            else
                r = mid - 1;
        }

        cout << ans << " " << val << "\n";
    }

    return 0;
}