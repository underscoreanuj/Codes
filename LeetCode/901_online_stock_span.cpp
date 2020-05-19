// stack solution

class StockSpanner
{
public:
    stack<pair<int, int>> stocks;
    StockSpanner()
    {
    }

    int next(int price)
    {
        int count = 1;
        while (!this->stocks.empty() && this->stocks.top().first <= price)
        {
            count += this->stocks.top().second;
            this->stocks.pop();
        }

        this->stocks.push({price, count});

        return count;
    }
};

auto speedup = []() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */

// dp solution

class StockSpanner
{
public:
    vector<int> stocks;
    vector<int> tab;
    StockSpanner()
    {
    }

    int next(int price)
    {
        this->stocks.emplace_back(price);
        int count = 1, idx = this->stocks.size() - 2;
        while (idx >= 0 && this->stocks[idx] <= price)
        {
            count += tab[idx];
            idx -= tab[idx];
        }
        tab.emplace_back(count);

        return count;
    }
};

auto speedup = []() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */