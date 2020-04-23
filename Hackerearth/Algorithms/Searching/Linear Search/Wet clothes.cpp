#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n = 0, m = 0, g = 0;
    cin >> n >> m >> g;

    vector<int> rains(n, 0);
    vector<int> clothes(m, 0);

    for (int i = 0; i < n; ++i)
        cin >> rains[i];

    for (int i = 0; i < m; ++i)
        cin >> clothes[i];

    int count = 0, start = 0, duration = 0;

    for (int i = 1; i < n; ++i)
    {
        duration = rains[i] - rains[i - 1];
        for (int j = 0; j < m; ++j)
        {
            if (clothes[j] <= duration)
            {
                ++count;
                clothes[j] = INT_MAX;
            }
        }
    }

    cout << count;

    return 0;
}