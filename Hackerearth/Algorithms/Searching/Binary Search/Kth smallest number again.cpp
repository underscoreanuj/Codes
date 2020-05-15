#include <bits/stdc++.h>

using namespace std;

#define ll long long int

auto speedup = []() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

vector<pair<ll, ll>> mergeIntervals(vector<pair<ll, ll>> &ranges)
{
    ll s = ranges[0].first, e = ranges[0].second;
    vector<pair<ll, ll>> result;
    for (int i = 1; i < ranges.size(); ++i)
    {
        // interval to be merged
        if (ranges[i].first >= s && ranges[i].first <= e)
        {
            e = max(e, ranges[i].second);
        }
        // disjoint interval
        else
        {
            result.push_back({s, e});
            s = ranges[i].first, e = ranges[i].second;
        }
    }
    result.push_back({s, e});

    return result;
}

int main()
{
    int t = 0, n = 0, q = 0, pos;
    ll a = 0, b = 0, k = 0;

    cin >> t;

    while (t--)
    {
        cin >> n >> q;
        vector<pair<ll, ll>> ranges(n);

        for (int i = 0; i < n; ++i)
        {
            cin >> a >> b;
            ranges[i] = make_pair(a, b);
        }

        sort(ranges.begin(), ranges.end());

        vector<pair<ll, ll>> range = mergeIntervals(ranges);
        vector<ll> rangeSum(range.size(), 0);

        for (int i = 0; i < rangeSum.size(); ++i)
        {
            rangeSum[i] = range[i].second - range[i].first + 1;
            if (i > 0)
                rangeSum[i] += rangeSum[i - 1];
        }

        while (q--)
        {
            cin >> k;

            pos = lower_bound(rangeSum.begin(), rangeSum.end(), k) - rangeSum.begin();

            if (pos == rangeSum.size())
                cout << "-1\n";
            else
            {
                if (pos > 0)
                {
                    k -= rangeSum[pos - 1];
                }
                cout << range[pos].first + k - 1 << "\n";
            }
        }
    }

    return 0;
}