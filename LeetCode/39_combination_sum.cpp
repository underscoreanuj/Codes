class Solution
{
public:
    vector<vector<int>> ret;

    void combinationSumUtil(vector<int> &candidates, vector<int> &sol, int target, int ind = 0)
    {
        if (target == 0)
        {
            ret.push_back(sol);
        }
        if (target < 0)
            return;

        for (int i = ind; i < candidates.size(); ++i)
        {
            sol.push_back(candidates[i]);
            combinationSumUtil(candidates, sol, target - candidates[i], i);
            sol.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        vector<int> sol;
        combinationSumUtil(candidates, sol, target);

        return ret;
    }
};