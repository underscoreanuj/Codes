#include <bits/stdc++.h>

using namespace std;

#define ll long long int

int main()
{
    int n = 0, q = 0;
    cin >> n;
    vector<ll> A(n, 0);
    for (int i = 0; i < n; ++i)
    {
        cin >> A[i];
    }
    sort(A.begin(), A.end());
    for (int i = 1; i < n; ++i)
    {
        A[i] += A[i - 1];
    }
    for (int i = 1; i < n; ++i)
    {
        A[i] /= (i + 1);
    }

    cin >> q;
    ll x;
    vector<ll>::iterator low;

    while (q--)
    {
        cin >> x;
        cout << (lower_bound(A.begin(), A.end(), x) - A.begin()) << "\n";
    }

    return 0;
}