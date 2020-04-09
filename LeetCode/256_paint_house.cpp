// solved on lintcode: https://www.lintcode.com/problem/paint-house/description

class Solution
{
public:
    /**
     * @param costs: n x 3 cost matrix
     * @return: An integer, the minimum cost to paint all houses
     */
    int minCost(vector<vector<int>> &costs)
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
