#include <bits/stdc++.h>

using namespace std;

#define ll long long int

int main()
{
    ll n = 0, total_xor = 0, xor_1 = 0, xor_2 = 0;
    cin >> n;

    vector<ll> a(n, 0);

    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
        total_xor ^= a[i];
    }

    total_xor = total_xor ^ (total_xor & (total_xor - 1));

    for (ll &e : a)
    {
        if ((e & total_xor) == 0)
            xor_1 ^= e;
        else
            xor_2 ^= e;
    }

    cout << min(xor_1, xor_2) << " " << max(xor_1, xor_2);

    return 0;
}