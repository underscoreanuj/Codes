// O(n) solution

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

// O(nlogn) solution

class Solution
{
public:
    int hIndex(vector<int> &citations)
    {
        sort(citations.begin(), citations.end());
        int len = citations.size();

        for (int i = 0; i < citations.size(); ++i)
        {
            if (citations[i] >= len - i)
                return len - i;
        }

        return 0;
    }
};