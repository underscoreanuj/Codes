#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n = 0, m = 0, idx = -1, x = 0;
    cin >> n >> m;

    for (int i = 0; i < n; ++i)
    {
        cin >> x;
        if (x == m)
            idx = i;
    }

    cout << idx + 1;

    return 0;
}