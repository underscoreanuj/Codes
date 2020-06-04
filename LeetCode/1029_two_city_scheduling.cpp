// sort solution O(nlogn)

class Solution
{
public:
    int twoCitySchedCost(vector<vector<int>> &costs)
    {
        sort(costs.begin(), costs.end(), [](const vector<int> &a, const vector<int> &b) {
            return (a[0] - a[1]) < (b[0] - b[1]);
        });

        int result = 0;
        int offset = costs.size() >> 1;
        for (int i = 0; i < offset; ++i)
            result += costs[i][0] + costs[i + offset][1];

        return result;
    }
};

auto speedup = []() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

// dp solution O(n^2)

class Solution
{
public:
    int twoCitySchedCost(vector<vector<int>> &costs)
    {
        int n = costs.size() >> 1;

        vector<vector<int>> tab(n + 1, vector<int>(n + 1, 0));

        for (int i = 1; i <= n; ++i)
            tab[i][0] = tab[i - 1][0] + costs[i - 1][0];
        for (int i = 1; i <= n; ++i)
            tab[0][i] = tab[0][i - 1] + costs[i - 1][1];

        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                tab[i][j] = min(tab[i - 1][j] + costs[i + j - 1][0], tab[i][j - 1] + costs[i + j - 1][1]);
            }
        }

        return tab[n][n];
    }
};

auto speedup = []() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();