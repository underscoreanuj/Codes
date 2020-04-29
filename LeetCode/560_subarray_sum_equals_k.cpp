class Solution
{
public:
    int subarraySum(vector<int> &nums, int k)
    {
        int n = nums.size(), sum = 0, result = 0;
        unordered_map<int, int> preSum = {{0, 1}};

        for (int i = 0; i < n; ++i)
        {
            sum += nums[i];
            if (preSum.count(sum - k))
                result += preSum[sum - k];
            ++preSum[sum];
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