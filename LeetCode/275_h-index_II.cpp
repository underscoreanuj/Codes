// O(logn) solution

class Solution
{
public:
    int hIndex(vector<int> &citations)
    {
        int n = citations.size();
        int l = 0, r = n - 1, mid = 0;

        while (l <= r)
        {
            mid = l + ((r - l) >> 1);

            if (citations[mid] >= n - mid)
                r = mid - 1;
            else
                l = mid + 1;
        }

        return n - l;
    }
};

auto speedup = []() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

// O(n) solution

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