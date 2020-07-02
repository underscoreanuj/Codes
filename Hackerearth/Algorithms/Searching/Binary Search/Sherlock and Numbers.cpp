#include <bits/stdc++.h>

using namespace std;

#define ll long long int

int main()
{
    ll t = 0, n = 0, k = 0, p = 0, x = 0, smaller = 0;
    cin >> t;

    while (t--)
    {
        cin >> n >> k >> p;

        smaller = 0;
        for (int i = 0; i < k; ++i)
        {
            cin >> x;
            if (x <= p + smaller)
                ++smaller;
        }

        if (n - k < p)
        {
            cout << "-1\n";
        }
        else
        {
            cout << p + smaller << "\n";
        }
    }

    return 0;
}