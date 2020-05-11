// iterative approach

class Solution
{
public:
    vector<vector<int>> subsetsWithDup(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result = {{}};
        vector<int> sol;
        int cur_size = 0, count = 0;

        for (int i = 0; i < nums.size(); ++i)
        {
            cur_size = result.size();
            count = 0;
            while (i + count < nums.size() && nums[i] == nums[i + count])
                ++count;
            for (int j = 0; j < cur_size; ++j)
            {
                sol = result[j];
                for (int k = 0; k < count; ++k)
                {
                    sol.emplace_back(nums[i]);
                    result.emplace_back(sol);
                }
            }
            i += count - 1;
        }

        return result;
    }
};

// recursive approach

class Solution
{
public:
    void subsetsWithDupUtil(vector<int> &nums, vector<vector<int>> &result, vector<int> &sol, int idx = 0)
    {
        result.push_back(sol);

        for (int i = idx; i < nums.size(); ++i)
        {
            if (i == idx || nums[i] != nums[i - 1])
            {
                sol.push_back(nums[i]);
                subsetsWithDupUtil(nums, result, sol, i + 1);
                sol.pop_back();
            }
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        vector<int> sol;
        subsetsWithDupUtil(nums, result, sol);

        return result;
    }
};