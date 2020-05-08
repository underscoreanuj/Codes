#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n = 0, m = 0;
    cin >> n >> m;
    vector<int> groups(n, 0);
    vector<int> planes(m, 0);

    for (int i = 0; i < n; ++i)
        cin >> groups[i];
    for (int i = 0; i < m; ++i)
        cin >> planes[i];

    sort(groups.rbegin(), groups.rend());
    sort(planes.rbegin(), planes.rend());

    if (groups[0] > planes[0])
    {
        cout << "-1";
        return 0;
    }

    int j = 0, time = 1;
    for (int i = 0; i < n; ++i)
    {
        if (j < m)
        {
            if (planes[j] >= groups[i])
                ++j;
            else
                time += 2;
        }
        else
        {
            time += 2 * (((n - i) / m) + 1);
            break;
        }
    }

    cout << time;

    return 0;
}