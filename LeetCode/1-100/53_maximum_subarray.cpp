class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        if (nums.size() == 1)
            return nums[0];

        int max_sum = INT_MIN, sum = 0;
        for (int n : nums)
        {
            sum += n;
            max_sum = max(max_sum, sum);
            if (sum < 0)
                sum = 0;
        }

        return max_sum;
    }
};