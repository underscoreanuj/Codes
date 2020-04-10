class Solution
{
public:
    int orangesRotting(vector<vector<int>> &grid)
    {
        queue<pair<int, int>> rotten;
        int fresh_count = 0;

        for (int i = 0; i < grid.size(); ++i)
        {
            for (int j = 0; j < grid[i].size(); ++j)
            {
                if (grid[i][j] == 2)
                    rotten.push({i, j});
                else if (grid[i][j] == 1)
                    ++fresh_count;
            }
        }

        if (fresh_count == 0)
            return 0;

        pair<int, int> tmp;
        int x = 0, y = 0, minutes = -1, q_size;
        vector<pair<int, int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        while (!rotten.empty())
        {
            q_size = rotten.size();
            ++minutes;

            while (q_size--)
            {
                tmp = rotten.front();
                rotten.pop();

                for (auto d : dirs)
                {
                    x = tmp.first + d.first;
                    y = tmp.second + d.second;
                    // if the cell is valid and has a fresh orange
                    if (x >= 0 && x < grid.size() && y >= 0 && y < grid[x].size() && grid[x][y] == 1)
                    {
                        grid[x][y] = 2; // make the cell's orange as rotten
                        --fresh_count;
                        rotten.push({x, y});
                    }
                }
            }
        }

        if (fresh_count > 0)
            return -1;

        return minutes;
    }
};