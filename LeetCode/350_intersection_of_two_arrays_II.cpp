class Solution
{
public:
    vector<int> intersect(vector<int> &nums1, vector<int> &nums2)
    {
        if (nums1.empty() || nums2.empty())
            return {};

        unordered_map<int, int> mem;
        vector<int> result;

        for (int &n : nums1)
            ++mem[n];

        for (int &n : nums2)
            if (mem.count(n))
            {
                result.push_back(n);
                --mem[n];
                if (mem[n] == 0)
                    mem.erase(n);
            }

        return result;
    }
};

auto speed = []() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();