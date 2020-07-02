class Solution
{
public:
    vector<vector<int>> ret;

    void permuteUniqueUtil(vector<int> nums, int ind = 0)
    {
        if (ind == nums.size())
        {
            ret.push_back(nums);
            return;
        }

        for (int i = ind; i < nums.size(); ++i)
        {
            if (i > ind && nums[i] == nums[ind])
                continue;
            swap(nums[i], nums[ind]);
            permuteUniqueUtil(nums, ind + 1);
        }
    }

    vector<vector<int>> permuteUnique(vector<int> &nums)
    {

        sort(nums.begin(), nums.end());
        permuteUniqueUtil(nums);

        return ret;
    }
};