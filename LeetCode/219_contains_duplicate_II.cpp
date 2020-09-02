class Solution
{
public:
    bool containsNearbyDuplicate(vector<int> &nums, int k)
    {
        unordered_set<int> mem;

        for (int i = 0; i < nums.size(); ++i)
        {
            if (mem.count(nums[i]))
                return true;
            mem.insert(nums[i]);
            if (i >= k)
                mem.erase(nums[i - k]);
        }

        return false;
    }
};

auto speedup = []() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();