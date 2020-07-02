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
    long long int n = 0, q = 0, m = 0;
    cin >> n >> q;
    vector<long long int> preSum(n, 0);
    for (int i = 0; i < n; ++i)
    {
        cin >> preSum[i];
        if (i > 0)
            preSum[i] += preSum[i - 1];
    }

    while (q--)
    {
        cin >> m;
        cout << (lower_bound(preSum.begin(), preSum.end(), m) - preSum.begin() + 1) << "\n";
    }

    return 0;
}