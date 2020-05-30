class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        if (nums.size() == 0)
            return 0;

        int j = 0, count = 1;
        for (int i = 1; i < nums.size(); ++i)
        {
            if (nums[i] == nums[i - 1])
                ++count;
            else
            {
                count = 1;
                ++j;
                nums[j] = nums[i];
            }

            if (count == 2)
            {
                ++j;
                nums[j] = nums[i];
            }
        }

        return j + 1;
    }
};