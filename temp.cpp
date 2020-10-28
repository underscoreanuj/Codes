#include <bits/stdc++.h>

#define ll long long int

using namespace std;

ll t, n, l, r;

int main()
{
    cin >> t;
    while (t--)
    {
        cin >> n;
        vector<ll> a(n, 0);
        ll result = 1;

        for (int i = 0; i < n; ++i)
        {
            cin >> a[i];
            if (i > 1 && a[i] < a[i - 1])
            {
                ++result;
            }
        }

        cout << result << "\n";
    }

    return 0;
}