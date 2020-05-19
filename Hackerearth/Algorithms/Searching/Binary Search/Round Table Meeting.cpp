#include <bits/stdc++.h>

using namespace std;

auto speedup = []() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

int main()
{
    int n = 0, q = 0, ele = 0, x = 0, y = 0, min_dist = 0, d = 0, p = 0;
    cin >> n >> q;
    vector<vector<int>> MEM(100001, vector<int>());
    for (int i = 0; i < n; ++i)
    {
        cin >> ele;
        MEM[ele].emplace_back(i + 1);
    }

    while (q--)
    {
        cin >> x >> y;

        min_dist = INT_MAX;
        for (int &pos : MEM[x])
        {
            p = lower_bound(MEM[y].begin(), MEM[y].end(), pos) - MEM[y].begin();
            if (p == 0)
            {
                d = min(MEM[y][p] - pos, pos + n - MEM[y][MEM[y].size() - 1]);
                min_dist = min(min_dist, d >> 1);
            }
            else if (p == MEM[y].size())
            {
                d = min(pos - MEM[y][p - 1], MEM[y][0] + n - pos);
                min_dist = min(min_dist, d >> 1);
            }
            else
            {
                d = min(MEM[y][p] - pos, pos + n - MEM[y][MEM[y].size() - 1]);
                min_dist = min(min_dist, d >> 1);
                d = min(pos - MEM[y][p - 1], MEM[y][0] + n - pos);
                min_dist = min(min_dist, d >> 1);
            }
        }

        cout << min_dist << "\n";
    }

    return 0;
}