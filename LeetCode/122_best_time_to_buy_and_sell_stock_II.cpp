class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int net_profit = 0;
        for (int i = 1; i < prices.size(); ++i)
            net_profit += max(prices[i] - prices[i - 1], 0);

        return net_profit;
    }
};