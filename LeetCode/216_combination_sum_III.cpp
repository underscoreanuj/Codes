class Solution
{
public:
    void combinationSum3Util(int k, int n, vector<vector<int>> &result, vector<int> &res, int start = 1)
    {
        if (n < 0 || k < 0)
            return;
        if (n == 0 && k == 0)
        {
            result.emplace_back(res);
            return;
        }

        for (int i = start; i <= 9; ++i)
        {
            res.emplace_back(i);
            combinationSum3Util(k - 1, n - i, result, res, i + 1);
            res.pop_back();
        }
    }

    vector<vector<int>> combinationSum3(int k, int n)
    {
        vector<vector<int>> result;
        vector<int> res;

        combinationSum3Util(k, n, result, res);

        return result;
    }
};

auto speedup = []() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();