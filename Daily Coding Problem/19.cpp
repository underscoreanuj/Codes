/*
 *
 * Good morning! Here's your coding interview problem for today.
 * This problem was asked by Facebook.
 * A builder is looking to build a row of N houses that can be of K different colors. He has a goal of minimizing cost while ensuring that no two neighboring houses are of the same color.
 * Given an N by K matrix where the nth row and kth column represents the cost to build the nth house with kth color, return the minimum cost which achieves this goal.
 * 
 * 
 * Online Judge: https://leetcode.com/problems/paint-house-ii/
 * Online Judge used: https://www.lintcode.com/en/old/problem/paint-house-ii/
 * 
 * 
*/

// my solution

class Solution
{
public:
    /**
     * @param costs: n x k cost matrix
     * @return: an integer, the minimum cost to paint all houses
     */
    int minCostII(vector<vector<int>> &costs)
    {
        // write your code here
        if (costs.size() == 0)
        {
            return 0;
        }
        if (costs.size() == 1)
        {
            return *min_element(costs[0].begin(), costs[0].end());
        }

        int n = costs.size(), k = costs[0].size();
        vector<vector<int>> tab(n, vector<int>(k, 0));
        vector<pair<int, int>> minT;
        int min_f = 0, min_s = 1, idx = 0;
        pair<int, int> prev;

        for (int i = 0; i < n; ++i)
        {
            min_f = 0;
            min_s = 1;
            for (int j = 0; j < k; ++j)
            {
                tab[i][j] = costs[i][j];

                if (i > 0)
                {
                    prev = minT.back();
                    idx = (j == prev.first ? prev.second : prev.first);
                    tab[i][j] += tab[i - 1][idx];
                }

                if (tab[i][j] < tab[i][min_f])
                {
                    min_s = min_f;
                    min_f = j;
                }
                else if (tab[i][j] < tab[i][min_s] && j != min_f)
                {
                    min_s = j;
                }
            }
            minT.push_back({min_f, min_s});
        }

        return *min_element(tab[n - 1].begin(), tab[n - 1].end());
    }
};