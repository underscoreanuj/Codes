class Solution
{
public:
    int maximumWealth(vector<vector<int>> &accounts)
    {
        int result = 0;
        for (auto &acc : accounts)
            result = max(result, accumulate(acc.begin(), acc.end(), 0));

        return result;
    }
};

auto speedup = []() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();