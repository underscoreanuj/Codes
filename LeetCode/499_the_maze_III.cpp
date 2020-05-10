// bfs solution

class Solution
{
public:
    /**
     * @param maze: the maze
     * @param ball: the ball position
     * @param hole: the hole position
     * @return: the lexicographically smallest way
     */
    string findShortestWay(vector<vector<int>> &maze, vector<int> &ball, vector<int> &hole)
    {
        // write your code here
        vector<pair<string, int>> result;
        vector<vector<bool>> vis(maze.size(), vector<bool>(maze[0].size(), false));
        vector<tuple<int, int, string>> dirs = {
            make_tuple(-1, 0, "u"), make_tuple(0, 1, "r"), make_tuple(1, 0, "d"), make_tuple(0, -1, "l")};
        queue<tuple<int, int, int, string>> Q;
        tuple<int, int, int, string> tmp;
        string tmp_res, res;
        int x = 0, y = 0, tmp_dist = 0, r = 0, c = 0, distance = 0;

        Q.push(make_tuple(ball[0], ball[1], 0, ""));

        while (!Q.empty())
        {
            tmp = Q.front();
            Q.pop();

            tie(r, c, distance, res) = tmp;
            vis[r][c] = true;

            for (auto d : dirs)
            {
                x = r + get<0>(d);
                y = c + get<1>(d);
                tmp_dist = distance;
                tmp_res = res + get<2>(d);

                while (x >= 0 && x < maze.size() && y >= 0 && y < maze[x].size() && maze[x][y] == 0)
                {
                    if (x == hole[0] && y == hole[1])
                    {
                        result.push_back({tmp_res, tmp_dist});
                    }
                    x += get<0>(d);
                    y += get<1>(d);

                    ++tmp_dist;
                }

                x -= get<0>(d);
                y -= get<1>(d);

                if (!vis[x][y])
                    Q.push(make_tuple(x, y, tmp_dist, tmp_res));
            }
        }

        if (result.size() == 0)
            return "impossible";

        sort(result.begin(), result.end(), [](const pair<string, int> &o1, const pair<string, int> &o2) {
            if (o1.second == o2.second)
            {
                return o1.first < o2.first;
            }
            return o1.second < o2.second;
        });

        return result[0].first;
    }
};