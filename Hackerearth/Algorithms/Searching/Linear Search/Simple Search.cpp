#include <bits/stdc++.h>

#define ll long long int

using namespace std;

int main()
{
    ll n = 0, k = 0;
    cin >> n;
    vector<ll> a(n, 0);

    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }

    cin >> k;

    for (int i = 0; i < n; ++i)
    {
        if (a[i] == k)
        {
            cout << i;
            return 0;
        }
    }

    cout << "-1";

    return 0;
}