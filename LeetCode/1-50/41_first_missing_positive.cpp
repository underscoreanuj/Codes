class Solution
{
public:
    int firstMissingPositive(vector<int> &nums)
    {
        if (nums.size() == 0)
            return 1;

        int p = 0, x = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
            if (nums[i] > 0)
                swap(nums[i], nums[p++]);
        }

        for (int i = 0; i < p; ++i)
        {
            x = abs(nums[i]) - 1;
            if (x < p && nums[x] > 0)
                nums[x] = -nums[x];
        }

        for (int i = 0; i < p; ++i)
        {
            if (nums[i] > 0)
                return i + 1;
        }

        return p + 1;
    }
};