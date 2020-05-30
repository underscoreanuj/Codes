class Solution
{
public:
    void nextPermutation(vector<int> &nums)
    {
        int ind = nums.size() - 2;
        while (ind >= 0 && nums[ind] >= nums[ind + 1])
            --ind;

        if (ind >= 0)
        {
            int i = nums.size() - 1;
            while (i > ind)
            {
                if (nums[i] > nums[ind])
                {
                    swap(nums[i], nums[ind]);
                    break;
                }
                --i;
            }
        }

        reverse(nums.begin() + ind + 1, nums.end());
    }
};