class Solution
{
public:
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
    {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<long long int>> tab(m, vector<long long int>(n, 0));

        for (int i = 0; i < m; ++i)
        {
            if (obstacleGrid[i][0] == 0)
            {
                tab[i][0] = 1;
            }
            else
                break;
        }

        for (int i = 0; i < n; ++i)
        {
            if (obstacleGrid[0][i] == 0)
            {
                tab[0][i] = 1;
            }
            else
                break;
        }

        for (int i = 1; i < m; ++i)
        {
            for (int j = 1; j < n; ++j)
            {
                if (obstacleGrid[i][j] == 0)
                {
                    tab[i][j] = tab[i - 1][j] + tab[i][j - 1];
                }
            }
        }

        return tab[m - 1][n - 1];
    }
};