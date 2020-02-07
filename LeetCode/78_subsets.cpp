class Solution
{
public:
    vector<vector<int>> subsets(vector<int> &nums)
    {
        if (nums.size() == 0)
            return {{}};
        vector<vector<int>> ret;
        vector<int> sol;
        int count = 1 << nums.size();

        for (int i = 0; i < count; ++i)
        {
            sol.clear();
            for (int j = 0; j < nums.size(); ++j)
            {
                if (i & (1 << j))
                    sol.emplace_back(nums[j]);
            }
            ret.emplace_back(sol);
        }

        return ret;
    }
};