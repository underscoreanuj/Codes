class Solution
{
public:
    void sortColors(vector<int> &nums)
    {
        int zero = 0, two = nums.size() - 1, i = 0;
        while (i < nums.size())
        {
            if (nums[i] == 0 && i > zero)
                swap(nums[i], nums[zero++]);
            else if (nums[i] == 2 && i < two)
                swap(nums[i], nums[two--]);
            else
                ++i;
        }
    }
};