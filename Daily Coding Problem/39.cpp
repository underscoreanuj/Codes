/**
 * Good morning! Here's your coding interview problem for today.
 * This problem was asked by Dropbox.
 * Conway's Game of Life takes place on an infinite two-dimensional board of square cells. Each cell is either dead or alive, and at each tick, the following rules apply:

    Any live cell with less than two live neighbours dies.
    Any live cell with two or three live neighbours remains living.
    Any live cell with more than three live neighbours dies.
    Any dead cell with exactly three live neighbours becomes a live cell.

 * A cell neighbours another cell if it is horizontally, vertically, or diagonally adjacent.
 * Implement Conway's Game of Life. It should be able to be initialized with a starting list of live cell coordinates and the number of steps it should run for. Once initialized, it should print out the board state at each step. Since it's an infinite board, print out only the relevant coordinates, i.e. from the top-leftmost live cell to bottom-rightmost live cell.
 * You can represent a live cell with an asterisk (*) and a dead cell with a dot (.).
 * 
 * 
 * 
 * Online Judge: https://leetcode.com/problems/game-of-life/
 * 
 */

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