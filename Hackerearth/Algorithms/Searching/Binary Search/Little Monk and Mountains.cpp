#include <bits/stdc++.h>

using namespace std;

#define ll long long int

int main()
{
    int n = 0, q = 0;
    cin >> n >> q;

    vector<ll> L(n, 0);
    vector<ll> R(n, 0);
    vector<ll> range(n, 0);

    for (int i = 0; i < n; ++i)
    {
        cin >> L[i] >> R[i];
        range[i] = R[i] - L[i] + 1;
        if (i > 0)
            range[i] += range[i - 1];
    }

    ll k = 0;
    int pos = -1;
    while (q--)
    {
        cin >> k;
        pos = lower_bound(range.begin(), range.end(), k) - range.begin();
        if (pos == 0)
        {
            cout << L[0] + k - 1 << "\n";
        }
        else
        {
            cout << L[pos] + (abs(range[pos - 1] - k)) - 1 << "\n";
        }
    }

    return 0;
}