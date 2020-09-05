class Solution
{
public:
    int hIndex(vector<int> &citations)
    {
        int n = citations.size();
        for (int i = 0; i < n; ++i)
        {
            if (citations[i] >= n - i)
                return n - i;
        }

        return 0;
    }
};

auto speedup = []() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();