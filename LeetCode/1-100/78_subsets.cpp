// iterative solution

class Solution
{
public:
    vector<vector<int>> subsets(vector<int> &nums)
    {
        if (nums.size() == 0)
            return {{}};
        vector<vector<int>> ret = {{}};
        vector<int> sol;
        int sz = 0;

        for (int n : nums)
        {
            sz = ret.size();
            for (int i = 0; i < sz; ++i)
            {
                sol.clear();
                sol = ret[i];
                sol.emplace_back(n);
                ret.emplace_back(sol);
            }
        }

        return ret;
    }
};

// recursive solution

class Solution
{
public:
    void subsetsUtil(vector<int> &nums, vector<vector<int>> &result, vector<int> &sol, int idx = 0)
    {
        result.emplace_back(sol);

        for (int i = idx; i < nums.size(); ++i)
        {
            sol.emplace_back(nums[i]);
            subsetsUtil(nums, result, sol, i + 1);
            sol.pop_back();
        }
    }

    vector<vector<int>> subsets(vector<int> &nums)
    {
        vector<vector<int>> result;
        vector<int> sol;
        subsetsUtil(nums, result, sol);

        return result;
    }
};

// bit manipulation solution

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