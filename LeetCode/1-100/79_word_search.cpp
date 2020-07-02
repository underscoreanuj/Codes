class Solution
{
public:
    vector<vector<bool>> vis;
    vector<pair<int, int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    bool existUtil(vector<vector<char>> &board, string &word, int r, int c, int idx = 0)
    {
        if (idx == word.length())
            return true;
        if (board[r][c] != word[idx] || vis[r][c])
            return false;
        if (idx == word.length() - 1)
            return true;

        vis[r][c] = true;

        int x = 0, y = 0;
        for (auto d : dirs)
        {
            x = r + d.first;
            y = c + d.second;

            if (x >= 0 && x < board.size() && y >= 0 && y < board[x].size() && !vis[x][y])
                if (existUtil(board, word, x, y, idx + 1))
                    return true;
        }

        vis[r][c] = false; // the backtracking step

        return false;
    }

    bool exist(vector<vector<char>> &board, string word)
    {
        vis = vector<vector<bool>>(board.size(), vector<bool>(board[0].size(), false));

        for (int i = 0; i < board.size(); ++i)
        {
            for (int j = 0; j < board[i].size(); ++j)
            {
                if (existUtil(board, word, i, j))
                    return true;
            }
        }

        return false;
    }
};

auto speedup = []() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();