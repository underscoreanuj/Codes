class Solution
{
public:
    bool containsDuplicate(vector<int> &nums)
    {
        unordered_set<int> distinct(nums.begin(), nums.end());

        return nums.size() != distinct.size();
    }
};

auto speedup = []() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();