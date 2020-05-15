#include <bits/stdc++.h>

using namespace std;

#define ll long long int

bool isValid(ll p, ll n)
{
    int sum = 0;
    while (p)
    {
        sum += p / 5;
        p /= 5;
    }

    return sum >= n;
}

int main()
{
    ll t = 0, n = 0;
    cin >> t;

    while (t--)
    {
        cin >> n;

        ll l = 1, r = 1e10, mid = 0, ans = 0;

        while (l <= r)
        {
            mid = l + ((r - l) >> 1);

            if (isValid(mid, n))
            {
                ans = mid;
                r = mid - 1;
            }
            else
                l = mid + 1;
        }

        cout << ans << "\n";
    }

    return 0;
}