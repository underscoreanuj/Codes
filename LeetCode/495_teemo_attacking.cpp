class Solution
{
public:
    int findPoisonedDuration(vector<int> &timeSeries, int duration)
    {
        if (timeSeries.size() == 0)
            return 0;

        int result = 0;
        for (int i = 0; i < timeSeries.size() - 1; ++i)
        {
            result += min(timeSeries[i + 1] - timeSeries[i], duration);
        }

        return result + duration;
    }
};

auto speedup = []() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();