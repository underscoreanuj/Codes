#include <bits/stdc++.h>

using namespace std;

#define ll long long int

int main()
{
    int n = 0, q = 0, m = 0;
    cin >> n;

    vector<ll> A(n, 0);
    for (int i = 0; i < n; ++i)
        cin >> A[i];

    sort(A.begin(), A.end());

    cin >> q;

    while (q--)
    {
        cin >> m;

        cout << lower_bound(A.begin(), A.end(), m) - A.begin() << "\n";
    }

    return 0;
}