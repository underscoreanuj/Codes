#include <bits/stdc++.h>

using namespace std;

#define ll long long int

int main()
{
    int t = 0, n = 0, pos = 0;
    ll k = 0, count = 0;
    cin >> t;

    while (t--)
    {
        cin >> n >> k;
        vector<ll> A(n, 0);
        count = 0;

        for (int i = 0; i < n; ++i)
        {
            cin >> A[i];
            if (i > 0)
                A[i] += A[i - 1];

            if (abs(A[i]) > k)
                ++count;
        }

        sort(A.begin(), A.end());

        for (int i = 0; i < n; ++i)
        {
            pos = upper_bound(A.begin(), A.end(), A[i] + k) - A.begin();
            count += (n - pos);
        }

        cout << count << "\n";
    }

    return 0;
}