class Solution
{
public:
    int findJudge(int N, vector<vector<int>> &trust)
    {
        vector<int> trust_balance(N + 1, 0);
        for (auto &t : trust)
        {
            --trust_balance[t[0]];
            ++trust_balance[t[1]];
        }
        for (int i = 1; i <= N; ++i)
            if (trust_balance[i] == N - 1)
                return i;
        return -1;
    }
};

auto speedup = []() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();