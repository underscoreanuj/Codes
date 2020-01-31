class Solution
{
public:
    vector<vector<int>> ret;

    void combinationSum2Util(vector<int> &candidates, vector<int> &sol, int target, int ind = 0)
    {
        if (target == 0)
        {
            ret.push_back(sol);
            return;
        }
        if (target < 0)
            return;

        for (int i = ind; i < candidates.size(); ++i)
        {
            if (i > ind && candidates[i] == candidates[i - 1])
                continue;
            sol.push_back(candidates[i]);
            combinationSum2Util(candidates, sol, target - candidates[i], i + 1);
            sol.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        sort(candidates.begin(), candidates.end());
        vector<int> sol;
        combinationSum2Util(candidates, sol, target);

        return ret;
    }
};