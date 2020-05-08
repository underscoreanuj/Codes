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
    int n = 0, q = 0, k = 0;
    cin >> n >> q;
    vector<int> a(n, 0);
    vector<int> preSum(n + 1, 0);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
        preSum[i + 1] = preSum[i] + __builtin_popcount(a[i]);
    }

    while (q--)
    {
        cin >> k;
        int min_len = INT_MAX;
        for (int i = 0; i < preSum.size(); ++i)
        {
            auto it = lower_bound(preSum.begin(), preSum.end(), preSum[i] + k);
            if (it == preSum.end())
                break;

            min_len = min(min_len, max((int)(it - (preSum.begin() + i)), 1));
        }
        if (min_len == INT_MAX)
            cout << "-1\n";
        else
            cout << min_len << "\n";
    }

    return 0;
}