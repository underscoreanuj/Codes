#include <bits/stdc++.h>

using namespace std;

#define ull size_t

int main()
{
    int t = 0, a = 0, b = 0, c = 0;
    ull k = 0, l = 0, r = 10000000000, mid = 0, val = 0;
    cin >> t;

    while (t--)
    {
        cin >> a >> b >> c >> k;
        l = 0;
        r = 10000000000;
        mid = 0;
        val = 0;

        while (l < r)
        {
            mid = l + ((r - l) >> 1);

            val = a * mid * mid + b * mid + c;

            if (val < k)
                l = mid + 1;
            else
                r = mid;
        }

        cout << l << "\n";
    }
    return 0;
}