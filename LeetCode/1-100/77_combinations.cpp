class Solution
{
public:
    vector<vector<int>> combine(int n, int k)
    {
        vector<vector<int>> ret;
        vector<int> sol(k, 0);
        int i = 0;

        while (i >= 0)
        {
            ++sol[i];
            if (sol[i] > n)
                --i;
            else if (i == k - 1)
                ret.emplace_back(sol);
            else
            {
                ++i;
                sol[i] = sol[i - 1];
            }
        }

        return ret;
    }
};