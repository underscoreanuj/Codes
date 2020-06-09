// recursive dfs + pruning

class Solution
{
public:
    void coinChangeUtil(vector<int> &coins, int amount, int idx, int count, int &res)
    {
        if (idx < 0 || count > res)
            return;

        if (amount % coins[idx] == 0)
        {
            res = min(res, count + amount / coins[idx]);
            return;
        }
        int div = amount / coins[idx];
        for (int i = div; i >= 0; --i)
        {
            if (count + i > res)
                return; // prioritize larger coins first, also prevents tle
            coinChangeUtil(coins, amount - (coins[idx] * i), idx - 1, count + i, res);
        }
    }

    int coinChange(vector<int> &coins, int amount)
    {
        sort(coins.begin(), coins.end());
        int res = INT_MAX;
        coinChangeUtil(coins, amount, coins.size() - 1, 0, res);

        return res == INT_MAX ? -1 : res;
    }
};

auto speedup = []() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

// recursive memoization

class Solution
{
public:
    int coinChangeUtil(vector<int> &coins, int amount, vector<int> &mem)
    {
        if (mem[amount] != INT_MAX)
            return mem[amount];

        int res = 0, min_count = INT_MAX;
        for (int &c : coins)
        {
            if (c <= amount)
            {
                res = coinChangeUtil(coins, amount - c, mem);
                if (res >= 0 && res < min_count)
                {
                    min_count = min(min_count, 1 + res);
                }
            }
        }

        mem[amount] = min_count == INT_MAX ? -1 : min_count;
        return mem[amount];
    }

    int coinChange(vector<int> &coins, int amount)
    {
        vector<int> mem(amount + 1, INT_MAX);
        mem[0] = 0;

        return coinChangeUtil(coins, amount, mem);
    }
};

// dp solution

class Solution
{
public:
    int coinChange(vector<int> &coins, int amount)
    {
        vector<int> tab(amount + 1, amount + 1);
        tab[0] = 0;

        for (int i = 1; i <= amount; ++i)
        {
            for (int &c : coins)
            {
                if (i >= c)
                    tab[i] = min(tab[i], 1 + tab[i - c]);
            }
        }

        return tab[amount] == amount + 1 ? -1 : tab[amount];
    }
};

auto speedup = []() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();