class Solution
{
public:
    bool isBelowThreshold(vector<int> &nums, int d, int thres)
    {
        int sum = 0;

        for (int &n : nums)
        {
            sum += ceil((float)n / (float)d);
        }

        return sum <= thres;
    }

    int smallestDivisor(vector<int> &nums, int threshold)
    {
        int l = 1, r = nums[nums.size() - 1], ans = 0, mid = 0; // this assumes that nums[nums.size()-1] is the max element of nums

        while (l <= r)
        {
            mid = l + ((r - l) >> 1);

            if (isBelowThreshold(nums, mid, threshold))
            {
                ans = mid;
                r = mid - 1;
            }
            else
                l = mid + 1;
        }

        return ans;
    }
};

auto speedup = []() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();