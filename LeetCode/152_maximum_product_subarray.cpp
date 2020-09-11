class Solution
{
public:
    int maxProduct(vector<int> &nums)
    {
        int l = 0, r = 0, result = INT_MIN, len = nums.size();

        for (int i = 0; i < nums.size(); ++i)
        {
            l = (l ? l : 1) * nums[i];
            r = (r ? r : 1) * nums[len - i - 1];

            result = max(result, max(l, r));
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