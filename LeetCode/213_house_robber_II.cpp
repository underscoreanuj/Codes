/*
    simply use any solution of house robber 1 (198) and call it for
    1. all houses except the first
    2. all houses except the last
    return the maximum of the two results
*/

class Solution
{
public:
    int robUtil(vector<int> &nums, int start, int end)
    {
        int incl = 0, excl = 0, tmp;
        for (int i = start; i < end; ++i)
        {
            tmp = incl;
            incl = max(incl, nums[i] + excl);
            excl = tmp;
        }
        return max(incl, excl);
    }

    int rob(vector<int> &nums)
    {
        if (nums.size() < 2)
            return nums.size() ? nums[0] : 0;

        return max(robUtil(nums, 0, nums.size() - 1), robUtil(nums, 1, nums.size()));
    }
};