#include <bits/stdc++.h>

using namespace std;

#define ll long long int

ll getPrice(vector<int> &B, ll ct)
{
    vector<ll> tmp(B.size(), 0);
    for (int i = 0; i < B.size(); ++i)
    {
        tmp[i] = B[i] + ct * (i + 1);
    }
    sort(tmp.begin(), tmp.end());
    ll sum = accumulate(tmp.begin(), tmp.begin() + ct, 0);

    return sum;
}

int main()
{
    int n = 0;
    ll sp = 0;
    cin >> n >> sp;
    vector<int> B(n, 0);

    for (int i = 0; i < n; ++i)
        cin >> B[i];

    ll l = 0, r = n, mid = 0;
    ll val = 0, ans = 0, price = 0;

    while (l <= r)
    {
        mid = l + ((r - l) >> 1);

        val = getPrice(B, mid);

        if (val <= sp)
        {
            l = mid + 1;
            ans = mid;
            price = val;
        }
        else
            r = mid - 1;
    }

    cout << ans << " " << price << "\n";

    return 0;
}