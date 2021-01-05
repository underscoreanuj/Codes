// prefix sum

class Solution
{
public:
    vector<int> runningSum(vector<int> &nums)
    {
        for (int i = 1; i < nums.size(); ++i)
            nums[i] += nums[i - 1];

        return nums;
    }
};

// direct use of partial_sum

class Solution
{
public:
    vector<int> runningSum(vector<int> &nums)
    {
        partial_sum(nums.begin(), nums.end(), nums.begin());

        return nums;
    }
};