#include <bits/stdc++.h>

using namespace std;

#define ll long long int

int main()
{
    int n = 0, q = 0;
    cin >> n;

    vector<ll> A(n, 0);
    for (int i = 0; i < n; ++i)
        cin >> A[i];

    sort(A.begin(), A.end());

    cin >> q;

    ll c = 0, x = 0;
    while (q--)
    {
        cin >> c >> x;

        if (c == 0)
        {
            cout << A.end() - lower_bound(A.begin(), A.end(), x) << "\n";
        }
        else
        {
            cout << A.end() - upper_bound(A.begin(), A.end(), x) << "\n";
        }
    }

    return 0;
}