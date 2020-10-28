class Solution
{
public:
    int removeCoveredIntervals(vector<vector<int>> &intervals)
    {
        if (intervals.size() == 0)
            return 0;

        int result = 1;

        sort(intervals.begin(), intervals.end(), [](const vector<int> &a, const vector<int> &b) {
            if (a[0] == b[0])
                return a[1] > b[1];
            return a[0] < b[0];
        });

        int start = intervals[0][0], end = intervals[0][1];

        for (int i = 1; i < intervals.size(); ++i)
        {
            if (start > intervals[i][0] || intervals[i][1] > end)
            {
                ++result;
                start = intervals[i][0];
                end = intervals[i][1];
            }
        }

        return result;
    }
};

auto speedup = []() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();