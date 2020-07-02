class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        if (intervals.size() == 0)
            return {};
        if (intervals.size() == 1)
            intervals;

        sort(intervals.begin(), intervals.end(), [](const vector<int> &o1, const vector<int> &o2) {
            return o1[0] < o2[0];
        });

        vector<vector<int>> ret;
        int f = 0, s = 0;

        int start = intervals[0][0], end = intervals[0][1];
        for (int i = 1; i < intervals.size(); ++i)
        {
            // disjoint interval encountered
            if (intervals[i][0] > end)
            {
                ret.push_back({start, end});
                start = intervals[i][0];
                end = intervals[i][1];
            }
            // overlapping intervals
            else
            {
                end = max(end, intervals[i][1]);
            }
        }

        ret.push_back({start, end});

        return ret;
    }
};