// solved on: https://www.lintcode.com/problem/the-maze-ii/description

// dijkstras priority queue solution

class Solution
{
public:
    /**
     * @param maze: the maze
     * @param start: the start
     * @param destination: the destination
     * @return: the shortest distance for the ball to stop at the destination
     */

    int shortestDistance(vector<vector<int>> &maze, vector<int> &start, vector<int> &destination)
    {
        // write your code here
        vector<vector<int>> dist(maze.size(), vector<int>(maze[0].size(), INT_MAX));
        dist[start[0]][start[1]] = 0;

        auto compare = [&dist](const pair<int, int> o1, const pair<int, int> o2) {
            return dist[o1.first][o1.second] > dist[o2.first][o2.second];
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(compare)> PQ(compare);
        for (int i = 0; i < dist.size(); ++i)
        {
            for (int j = 0; j < dist[i].size(); ++j)
                PQ.push({i, j});
        }

        vector<pair<int, int>> dirs = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
        int x = 0, y = 0, distance = 0;

        while (!PQ.empty())
        {
            auto cur = PQ.top();
            PQ.pop();

            if (dist[cur.first][cur.second] == INT_MAX)
                continue;
            if (cur.first == destination[0] && cur.second == destination[1])
                break;

            for (auto d : dirs)
            {
                x = cur.first + d.first;
                y = cur.second + d.second;
                distance = 0;

                while (x >= 0 && x < maze.size() && y >= 0 && y < maze[x].size() && maze[x][y] == 0)
                {
                    x += d.first;
                    y += d.second;
                    ++distance;
                }
                x -= d.first;
                y -= d.second;

                if (dist[cur.first][cur.second] + distance < dist[x][y])
                {
                    dist[x][y] = dist[cur.first][cur.second] + distance;
                    PQ.push({x, y});
                }
            }
        }

        return dist[destination[0]][destination[1]] == INT_MAX ? -1 : dist[destination[0]][destination[1]];
    }
};

// better dfs solution

class Solution
{
public:
    /**
     * @param maze: the maze
     * @param start: the start
     * @param destination: the destination
     * @return: the shortest distance for the ball to stop at the destination
     */

    void shortestDistanceUtil(vector<vector<int>> &maze, vector<vector<int>> &dist, int row, int col, vector<int> &dest)
    {

        if (row == dest[0] && col == dest[1])
            return;

        static vector<pair<int, int>> dirs = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
        int x = 0, y = 0, distance = 0;

        for (auto d : dirs)
        {
            x = row + d.first;
            y = col + d.second;
            distance = 0;

            while (x >= 0 && x < maze.size() && y >= 0 && y < maze[x].size() && maze[x][y] == 0)
            {
                x += d.first;
                y += d.second;
                ++distance;
            }

            if (dist[row][col] + distance < dist[x - d.first][y - d.second])
            {
                dist[x - d.first][y - d.second] = dist[row][col] + distance;
                shortestDistanceUtil(maze, dist, x - d.first, y - d.second, dest);
            }
        }
    }

    int shortestDistance(vector<vector<int>> &maze, vector<int> &start, vector<int> &destination)
    {
        // write your code here
        vector<vector<int>> dist(maze.size(), vector<int>(maze[0].size(), INT_MAX));
        dist[start[0]][start[1]] = 0;
        shortestDistanceUtil(maze, dist, start[0], start[1], destination);

        return dist[destination[0]][destination[1]] == INT_MAX ? -1 : dist[destination[0]][destination[1]];
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
     * @return: the shortest distance for the ball to stop at the destination
     */

    int shortestDistanceUtil(vector<vector<int>> &maze, vector<vector<bool>> &vis, int row, int col, vector<int> &dest, int dist = 0)
    {

        if (vis[row][col])
            return -1;
        if (row == dest[0] && col == dest[1])
            return dist;

        vis[row][col] = true;

        static vector<pair<int, int>> dirs = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
        int x = 0, y = 0, tmp_dist = dist, res = 0, result = INT_MAX;

        for (auto d : dirs)
        {
            x = row + d.first;
            y = col + d.second;
            tmp_dist = dist + 1;

            while (x >= 0 && x < maze.size() && y >= 0 && y < maze[x].size() && maze[x][y] == 0)
            {
                x += d.first;
                y += d.second;
                ++tmp_dist;
            }

            res = shortestDistanceUtil(maze, vis, x - d.first, y - d.second, dest, tmp_dist - 1);

            if (res != -1)
                result = min(result, res);
        }

        vis[row][col] = false;

        return result == INT_MAX ? -1 : result;
    }

    int shortestDistance(vector<vector<int>> &maze, vector<int> &start, vector<int> &destination)
    {
        // write your code here
        vector<vector<bool>> vis(maze.size(), vector<bool>(maze[0].size(), false));
        return shortestDistanceUtil(maze, vis, start[0], start[1], destination);
    }
};

// bfs solution

class Solution
{
public:
    /**
     * @param maze: the maze
     * @param start: the start
     * @param destination: the destination
     * @return: the shortest distance for the ball to stop at the destination
     */
    int shortestDistance(vector<vector<int>> &maze, vector<int> &start, vector<int> &destination)
    {
        // write your code here
        vector<vector<bool>> vis(maze.size(), vector<bool>(maze[0].size(), false));
        vector<pair<int, int>> dirs = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
        queue<tuple<int, int, int>> Q;
        tuple<int, int, int> tmp;
        int x = 0, y = 0, r = 0, c = 0, dist = 0, tmp_dist = 0;

        Q.push(make_tuple(start[0], start[1], 0));

        while (!Q.empty())
        {
            tmp = Q.front();
            Q.pop();

            tie(r, c, dist) = tmp;
            vis[r][c] = true;
            tmp_dist = dist;

            for (auto d : dirs)
            {
                x = r + d.first;
                y = c + d.second;
                ++tmp_dist;

                while (x >= 0 && x < maze.size() && y >= 0 && y < maze[x].size() && maze[x][y] == 0)
                {
                    x += d.first;
                    y += d.second;
                    ++tmp_dist;
                }

                x -= d.first;
                y -= d.second;
                --tmp_dist;

                if (x == destination[0] && y == destination[1])
                    return tmp_dist;

                if (!vis[x][y])
                    Q.push(make_tuple(x, y, tmp_dist));

                tmp_dist = dist;
            }
        }

        return -1;
    }
};