class Solution
{
public:
    int rob(vector<int> &nums)
    {
        if (nums.size() == 0)
            return 0;
        if (nums.size() == 1)
            return nums[0];
        if (nums.size() == 2)
            return max(nums[0], nums[1]);

        int incl = nums[0], excl = 0, tmp = 0;

        for (int i = 1; i < nums.size(); ++i)
        {
            tmp = incl;
            incl = max(incl, nums[i] + excl);
            excl = tmp;
        }

        return max(incl, excl);
    }
};