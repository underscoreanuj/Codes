class Solution
{
public:
    void gameOfLife(vector<vector<int>> &board)
    {
        vector<pair<int, int>> dirs = {
            {-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}};
        int x = 0, y = 0, live_count = 0;

        for (int i = 0; i < board.size(); ++i)
        {
            for (int j = 0; j < board[i].size(); ++j)
            {
                live_count = 0;
                for (auto &d : dirs)
                {
                    x = i + d.first;
                    y = j + d.second;

                    if (x >= 0 && x < board.size() && y >= 0 && y < board[x].size())
                    {
                        if (board[x][y] == 1 || board[x][y] == '*')
                            ++live_count;
                        ;
                    }
                }
                if (board[i][j] == 1)
                {
                    if (live_count < 2 || live_count > 3)
                        board[i][j] = '*';
                }
                else
                {
                    if (live_count == 3)
                        board[i][j] = '?';
                }
            }
        }

        for (int i = 0; i < board.size(); ++i)
        {
            for (int j = 0; j < board[i].size(); ++j)
            {
                board[i][j] = (board[i][j] == 1 || board[i][j] == '?') ? 1 : 0;
            }
        }
    }
};

auto speedup = []() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();