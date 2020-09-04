class Solution
{
public:
    vector<int> partitionLabels(string S)
    {
        vector<int> result, mem(128, -1);
        int last_idx = -1, len = 0;

        for (int i = 0; i < S.length(); ++i)
            mem[S[i]] = i;

        for (int i = 0; i < S.length(); ++i)
        {
            last_idx = max(last_idx, mem[S[i]]);
            ++len;
            if (i == last_idx)
            {
                result.emplace_back(len);
                len = 0;
            }
        }

        return result;
    }
};

auto speedup = []() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();