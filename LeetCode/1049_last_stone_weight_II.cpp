/*
    the idea is to get the closest to the half value of the total weight of the stones
    we do it by using a modified 0/1 knapsack dp algorithm such that the weight is the value itself
*/

class Solution
{
public:
    int lastStoneWeightII(vector<int> &stones)
    {
        int sum = accumulate(stones.begin(), stones.end(), 0);
        int target = sum >> 1;
        int closest = -1;

        vector<vector<int>> tab(stones.size(), vector<int>(target + 1, -1));
        tab[0][0] = 0;
        tab[0][stones[0]] = stones[0];

        for (int r = 1; r < stones.size(); ++r)
        {
            for (int w = 0; w <= target; ++w)
            {
                tab[r][w] = tab[r - 1][w];
                if (stones[r] <= w && tab[r - 1][w - stones[r]] >= 0)
                {
                    tab[r][w] = w;
                }
                closest = max(closest, tab[r][w]);
            }
        }

        return abs(sum - 2 * closest);
    }
};