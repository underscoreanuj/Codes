// bfs solution

class Solution
{
public:
    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int newColor)
    {
        if (image[sr][sc] == newColor)
            return image;

        vector<pair<int, int>> dirs = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
        queue<pair<int, int>> Q;
        pair<int, int> tmp;
        Q.push({sr, sc});
        int color = image[sr][sc], x = 0, y = 0;

        while (!Q.empty())
        {
            tmp = Q.front();
            Q.pop();

            image[tmp.first][tmp.second] = newColor;

            for (auto d : dirs)
            {
                x = tmp.first + d.first;
                y = tmp.second + d.second;

                if (x >= 0 && x < image.size() && y >= 0 && y < image[x].size() && image[x][y] == color)
                {
                    Q.push({x, y});
                }
            }
        }

        return image;
    }
};

auto speedup = []() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

// dfs solution

class Solution
{
public:
    void floodFillUtil(vector<vector<int>> &image, int r, int c, int oldColor, int newColor)
    {
        if (r < 0 || r >= image.size() || c < 0 || c >= image[r].size() || image[r][c] != oldColor)
            return;

        static vector<pair<int, int>> dirs = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

        image[r][c] = newColor;

        for (auto d : dirs)
        {
            floodFillUtil(image, r + d.first, c + d.second, oldColor, newColor);
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int newColor)
    {
        if (image[sr][sc] == newColor)
            return image;
        floodFillUtil(image, sr, sc, image[sr][sc], newColor);

        return image;
    }
};

auto speedup = []() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();