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
    int n = 0, q = 0, pos;
    ll r = 0;
    long double x = 0, y = 0;

    cin >> n;
    vector<ll> dist(n, 0);

    for (int i = 0; i < n; ++i)
    {
        cin >> x >> y;
        dist[i] = ceil(sqrt(x * x + y * y));
    }

    sort(dist.begin(), dist.end());

    cin >> q;

    while (q--)
    {
        cin >> r;

        pos = upper_bound(dist.begin(), dist.end(), r) - dist.begin();

        cout << pos << "\n";
    }

    return 0;
}