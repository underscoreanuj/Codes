class Solution
{
public:
    int hIndex(vector<int> &citations)
    {
        int len = citations.size(), count = 0;
        vector<int> buckets(len + 1, 0);

        for (int &c : citations)
        {
            if (c >= len)
                ++buckets[len];
            else
                ++buckets[c];
        }

        for (int i = len; i >= 0; --i)
        {
            count += buckets[i];
            if (count >= i)
                return i;
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