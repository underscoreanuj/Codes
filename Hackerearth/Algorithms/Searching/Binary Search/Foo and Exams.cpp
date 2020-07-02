#include <bits/stdc++.h>

using namespace std;

#define ll long long int

int main()
{
    ll t = 0, a = 0, b = 0, c = 0, d = 0, k = 0;
    cin >> t;

    while (t--)
    {
        cin >> a >> b >> c >> d >> k;

        int l = 0, r = 1e6, mid = 0, fin_t = 0;
        size_t cur_ft = 0;

        while (l <= r)
        {
            mid = l + ((r - l) >> 1);

            cur_ft = a * powl(mid, 3) + b * powl(mid, 2) + c * powl(mid, 1) + d;

            if (cur_ft <= k)
            {
                fin_t = mid;
                l = mid + 1;
            }
            else
                r = mid - 1;
        }

        cout << fin_t << "\n";
    }
    return 0;
}