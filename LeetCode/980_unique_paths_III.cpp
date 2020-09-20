class Solution
{
public:
    void uniquePathsIIIUtil(vector<vector<int>> &grid, int row, int col, int &count, int non_obstacle_count)
    {
        static vector<pair<int, int>> dirs = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

        if (grid[row][col] == 2 && non_obstacle_count == 1)
        {
            ++count;
            return;
        }

        int cur_val = grid[row][col];
        grid[row][col] = -9;

        int x = 0, y = 0;
        for (auto d : dirs)
        {
            x = row + d.first;
            y = col + d.second;

            if (x >= 0 && x < grid.size() && y >= 0 && y < grid[0].size() && grid[x][y] >= 0)
                uniquePathsIIIUtil(grid, x, y, count, non_obstacle_count - 1);
        }

        grid[row][col] = cur_val;
    }

    int uniquePathsIII(vector<vector<int>> &grid)
    {
        int count = 0, non_obstacle_count = 0;

        int x = -1, y = -1;

        for (int i = 0; i < grid.size(); ++i)
        {
            for (int j = 0; j < grid[0].size(); ++j)
            {
                if (grid[i][j] == 1)
                {
                    x = i;
                    y = j;
                }
                if (grid[i][j] != -1)
                    ++non_obstacle_count;
            }
        }

        uniquePathsIIIUtil(grid, x, y, count, non_obstacle_count);

        return count;
    }
};

auto speedup = []() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();