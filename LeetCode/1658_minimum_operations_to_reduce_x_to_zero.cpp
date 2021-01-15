class Solution
{
public:
    int minOperations(vector<int> &nums, int x)
    {
        long target = -x, sum = 0;
        int result = 0, l = 0, n = nums.size();
        for (int &n : nums)
            target += n;

        for (int r = 0; r < n; ++r)
        {
            sum += nums[r];
            while (l < r && sum > target)
                sum -= nums[l++];
            if (sum == target)
                result = max(result, r - l + 1);
        }

        return result ? nums.size() - result : target ? -1 : nums.size();
    }
};

auto speedup = []() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();