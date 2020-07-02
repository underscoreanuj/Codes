#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n = 0, m = 0, k = 0, count = 0, x = 0;
    cin >> n >> m >> k;
    set<int> rows;
    vector<int> row_count(m, 0);

    for (int i = 1; i <= m; ++i)
    {
        rows.insert(i);
    }

    for (int i = 0; i < n; ++i)
    {
        cin >> x;
        if (!rows.empty())
        {
            auto it = rows.lower_bound(x);
            if (it == rows.end())
                it = rows.begin();

            if (*it != x)
                ++count;
            ++row_count[*it];
            if (row_count[*it] == k)
                rows.erase(*it);
        }
        else
            ++count;
    }

    cout << count;

    return 0;
}