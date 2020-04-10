// dfs solution

class Solution
{
public:
    void markIslandDFS(vector<vector<char>> &grid, int i, int j)
    {
        // if invalid cell or cell is not a part of island
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[i].size() || grid[i][j] != '1')
            return;

        // mark current cell as visited
        grid[i][j] = '2';

        // mark all neighbouring cells that are valid
        markIslandDFS(grid, i + 1, j);
        markIslandDFS(grid, i - 1, j);
        markIslandDFS(grid, i, j + 1);
        markIslandDFS(grid, i, j - 1);
    }

    int numIslands(vector<vector<char>> &grid)
    {
        int island_count = 0;
        for (int i = 0; i < grid.size(); ++i)
        {
            for (int j = 0; j < grid[i].size(); ++j)
            {
                if (grid[i][j] == '1')
                {
                    ++island_count;
                    markIslandDFS(grid, i, j);
                }
            }
        }

        return island_count;
    }
};

// bfs solution

class Solution
{
public:
    void markIslandBFS(vector<vector<char>> &grid, int i, int j)
    {
        grid[i][j] = '2'; // mark the current land as visited

        static vector<pair<int, int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        queue<pair<int, int>> Q;
        pair<int, int> cur;
        int x = 0, y = 0;

        Q.push({i, j});
        while (!Q.empty())
        {
            cur = Q.front();
            Q.pop();

            for (auto d : dirs)
            {
                x = cur.first + d.first;
                y = cur.second + d.second;
                if (x >= 0 && x < grid.size() && y >= 0 && y < grid[x].size() && grid[x][y] == '1')
                {
                    grid[x][y] = '2'; // mark the current land as visited
                    Q.push({x, y});
                }
            }
        }
    }

    int numIslands(vector<vector<char>> &grid)
    {
        int island_count = 0;
        for (int i = 0; i < grid.size(); ++i)
        {
            for (int j = 0; j < grid[i].size(); ++j)
            {
                if (grid[i][j] == '1')
                {
                    ++island_count;
                    markIslandBFS(grid, i, j);
                }
            }
        }

        return island_count;
    }
};