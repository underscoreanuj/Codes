// solved on : https://www.lintcode.com/problem/the-maze/description

// bfs solution

class Solution
{
public:
    /**
     * @param maze: the maze
     * @param start: the start
     * @param destination: the destination
     * @return: whether the ball could stop at the destination
     */

    bool hasPath(vector<vector<int>> &maze, vector<int> &start, vector<int> &destination)
    {
        // write your code here
        queue<pair<int, int>> Q;
        vector<vector<bool>> vis(maze.size(), vector<bool>(maze[0].size(), false));
        vector<pair<int, int>> dirs = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
        int x = 0, y = 0;
        pair<int, int> tmp;
        Q.push({start[0], start[1]});

        while (!Q.empty())
        {
            tmp = Q.front();
            Q.pop();
            vis[tmp.first][tmp.second] = true;

            for (auto d : dirs)
            {
                x = tmp.first + d.first;
                y = tmp.second + d.second;

                while (x >= 0 && x < maze.size() && y >= 0 && y < maze[x].size() && maze[x][y] == 0)
                {
                    x += d.first;
                    y += d.second;
                }
                x -= d.first;
                y -= d.second;

                if (x == destination[0] && y == destination[1])
                    return true;

                if (!vis[x][y])
                    Q.push({x, y});
            }
        }

        return false;
    }
};

// dfs solution

class Solution
{
public:
    /**
     * @param maze: the maze
     * @param start: the start
     * @param destination: the destination
     * @return: whether the ball could stop at the destination
     */
    bool hasPathUtil(vector<vector<int>> &maze, vector<vector<bool>> &vis, int row, int col, vector<int> &dest)
    {
        if (vis[row][col])
            return false;
        if (row == dest[0] && col == dest[1])
            return true;

        vis[row][col] = true;

        static vector<pair<int, int>> dirs = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
        int x = 0, y = 0;

        for (auto d : dirs)
        {
            x = row + d.first;
            y = col + d.second;

            while (x >= 0 && x < maze.size() && y >= 0 && y < maze[x].size() && maze[x][y] == 0)
            {
                x += d.first;
                y += d.second;
            }

            if (hasPathUtil(maze, vis, x - d.first, y - d.second, dest))
                return true;
        }

        return false;
    }

    bool hasPath(vector<vector<int>> &maze, vector<int> &start, vector<int> &destination)
    {
        // write your code here
        vector<vector<bool>> vis(maze.size(), vector<bool>(maze[0].size(), false));
        return hasPathUtil(maze, vis, start[0], start[1], destination);
    }
};