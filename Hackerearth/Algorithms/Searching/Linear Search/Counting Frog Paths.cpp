#include <bits/stdc++.h>

using namespace std;

int main()
{
    int x = 0, y = 0, s = 0, t = 0, count = 0;
    cin >> x >> y >> s >> t;

    for (int i = x; i <= x + s; ++i)
    {
        for (int j = y; j <= y + s; ++j)
        {
            if (i + j <= t)
                ++count;
        }
    }

    cout << count;

    return 0;
}