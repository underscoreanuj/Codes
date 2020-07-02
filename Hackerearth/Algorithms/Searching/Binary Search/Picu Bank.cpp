#include <bits/stdc++.h>

using namespace std;

#define ll long long int

bool isValid(ll months, ll d, ll a, ll m, ll b, ll x)
{
    ll a_mult = (months / (m + 1)) * m + months % (m + 1);
    ll b_mult = (months / (m + 1));
    return (d + a * a_mult + b * b_mult) >= x;
}

int main()
{
    ll t = 0, d = 0, a = 0, m = 0, b = 0, x = 0;
    cin >> t;

    while (t--)
    {
        cin >> d >> a >> m >> b >> x;
        ll left = 0, right = 1000000000, mid = 0;
        bool val = false;

        while (left < right)
        {
            mid = left + ((right - left) >> 1);

            val = isValid(mid, d, a, m, b, x);

            if (val)
                right = mid;
            else
                left = mid + 1;
        }

        cout << left << "\n";
    }

    return 0;
}