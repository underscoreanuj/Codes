class Solution
{
public:
    vector<vector<int>> ret;

    void permuteUtil(vector<int> &nums, int ind)
    {
        if (ind == nums.size())
        {
            ret.push_back(nums);
            return;
        }

        for (int i = ind; i < nums.size(); ++i)
        {
            swap(nums[i], nums[ind]);
            permuteUtil(nums, ind + 1);
            swap(nums[i], nums[ind]);
        }
    }

    vector<vector<int>> permute(vector<int> &nums)
    {
        permuteUtil(nums, 0);
        return ret;
    }
};