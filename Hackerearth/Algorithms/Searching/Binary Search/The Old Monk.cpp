#include <bits/stdc++.h>

using namespace std;

#define ll long long int

int main()
{
    int t = 0, n = 0;
    cin >> t;

    while (t--)
    {
        cin >> n;
        vector<ll> A(n, 0);
        vector<ll> B(n, 0);

        for (int i = 0; i < n; ++i)
            cin >> A[i];
        for (int i = 0; i < n; ++i)
            cin >> B[i];

        reverse(B.begin(), B.end());
        int j = 0;

        ll ans = LONG_MIN;

        for (int i = 0; i < n; ++i)
        {
            if (A[i] > B[0])
            {
                ans = max(ans, (ll)0);
            }
            j = lower_bound(B.begin(), B.end(), A[i]) - B.begin();
            j = n - j - 1;

            if (j >= i)
                ans = max(ans, (ll)(j - i));
            else
                ans = max(ans, (ll)0);
        }

        cout << ans << "\n";
    }

    return 0;
}