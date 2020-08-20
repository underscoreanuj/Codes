class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        if (prices.size() == 0)
            return 0;

        int min_so_far = prices[0], max_profit = INT_MIN;

        for (int i = 1; i < prices.size(); ++i)
        {
            max_profit = max(max_profit, prices[i] - min_so_far);
            min_so_far = min(min_so_far, prices[i]);
        }

        return max(max_profit, 0);
    }
};

auto speedup = []() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();