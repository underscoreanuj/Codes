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
    ll n, q, c;

    cin >> n >> q;
    vector<ll> A(n, 0);
    for (int i = 0; i < n; ++i)
    {
        cin >> A[i];
        if (i > 0)
            A[i] += A[i - 1];
    }

    while (q--)
    {
        cin >> c;
        cout << (lower_bound(A.begin(), A.end(), c) - A.begin() + 1) << "\n";
    }

    return 0;
}