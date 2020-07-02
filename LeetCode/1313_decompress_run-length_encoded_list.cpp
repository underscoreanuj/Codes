class Solution
{
public:
    vector<int> decompressRLElist(vector<int> &nums)
    {
        vector<int> result;

        for (int i = 0; i < nums.size(); i += 2)
            for (int j = 0; j < nums[i]; ++j)
                result.push_back(nums[i + 1]);

        return result;
    }
};

auto speedup = []() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();