class Solution
{
public:
    vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
    {
        if (nums1.empty() || nums2.empty())
            return {};

        vector<int> result;
        unordered_set<int> mem(nums1.begin(), nums1.end());

        for (int &n : nums2)
            if (mem.count(n))
            {
                result.push_back(n);
                mem.erase(n);
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