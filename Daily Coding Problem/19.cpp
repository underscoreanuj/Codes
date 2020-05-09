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
            return 0;

        if (costs.size() == 1)
            return *min_element(costs[0].begin(), costs[0].end());

        pair<int, int> minTab; // stores the minimum and second minimum of each preceeding row

        int first_min = 0, second_min = 0;

        for (int i = 0; i < costs.size(); ++i)
        {
            first_min = 0, second_min = 1;
            for (int j = 0; j < costs[i].size(); ++j)
            {
                if (i > 0)
                {
                    if (j == minTab.first)
                    {
                        costs[i][j] += costs[i - 1][minTab.second];
                    }
                    else
                    {
                        costs[i][j] += costs[i - 1][minTab.first];
                    }
                }
                if (costs[i][first_min] > costs[i][j])
                {
                    second_min = first_min;
                    first_min = j;
                }
                else if (costs[i][second_min] > costs[i][j] && j != first_min)
                {
                    second_min = j;
                }
            }
            minTab = {first_min, second_min};
        }

        return *min_element(costs[costs.size() - 1].begin(), costs[costs.size() - 1].end());
    }
};
