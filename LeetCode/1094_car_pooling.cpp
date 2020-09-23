// O(n) solution using bucket sort

class Solution
{
public:
    bool carPooling(vector<vector<int>> &trips, int capacity)
    {
        vector<int> tab(1001, 0);
        int total = 0;

        for (auto &trip : trips)
        {
            tab[trip[1]] += trip[0];
            tab[trip[2]] -= trip[0];
        }

        for (auto &t : tab)
        {
            total += t;
            if (total > capacity)
                return false;
        }

        return true;
    }
};

auto speedup = []() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

// O(nlogn) solution

class Solution
{
public:
    bool carPooling(vector<vector<int>> &trips, int capacity)
    {
        vector<pair<int, int>> tab;
        int total = 0;

        for (auto &trip : trips)
        {
            tab.emplace_back(trip[1], trip[0]);
            tab.emplace_back(trip[2], -trip[0]);
        }

        sort(tab.begin(), tab.end());

        for (auto &t : tab)
        {
            total += t.second;
            if (total > capacity)
                return false;
        }

        return true;
    }
};

auto speedup = []() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();