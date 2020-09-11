class Solution
{
public:
    int numSubarrayProductLessThanK(vector<int> &nums, int k)
    {
        if (k <= 1)
            return 0;

        int l = 0, prod = 1, result = 0;

        for (int r = 0; r < nums.size(); ++r)
        {
            prod *= nums[r];
            while (prod >= k)
                prod /= nums[l++];
            result += (r - l + 1);
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