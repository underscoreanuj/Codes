class Solution
{
public:
    bool isValid(vector<vector<char>> &board, char e, int i, int j)
    {
        for (int k = 0; k < 9; ++k)
        {
            if (board[k][j] == e)
                return false;
            if (board[i][k] == e)
                return false;
            if (board[(i / 3) * 3 + (k / 3)][(j / 3) * 3 + (k % 3)] == e)
                return false;
        }
        return true;
    }

    bool solveSudokuUtil(vector<vector<char>> &board)
    {
        for (int i = 0; i < 9; ++i)
        {
            for (int j = 0; j < 9; ++j)
            {
                if (board[i][j] == '.')
                {
                    for (char c = '1'; c <= '9'; ++c)
                    {
                        if (isValid(board, c, i, j))
                        {
                            board[i][j] = c;
                            if (solveSudokuUtil(board))
                                return true;
                            board[i][j] = '.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }

    void solveSudoku(vector<vector<char>> &board)
    {
        cout << solveSudokuUtil(board);
    }
};