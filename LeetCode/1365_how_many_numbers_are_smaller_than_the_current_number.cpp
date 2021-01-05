class Solution
{
public:
    vector<int> smallerNumbersThanCurrent(vector<int> &nums)
    {
        int n = nums.size(), cur = 0, count = 0;
        vector<int> result(n, 0);
        vector<int> idx(101, 0);

        for (int i = 0; i < n; ++i)
            ++idx[nums[i]];
        for (int i = 1; i < 101; ++i)
            idx[i] += idx[i - 1];
        for (int i = 0; i < n; ++i)
            result[i] = nums[i] == 0 ? 0 : idx[nums[i] - 1];

        return result;
    }
};

auto speedup = []() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();