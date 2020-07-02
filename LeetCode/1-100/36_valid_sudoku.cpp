class Solution
{
public:
    bool validateUtil(vector<vector<char>> &board, int i, int j)
    {
        int row_offset = (i / 3) * 3;
        int col_offset = (j / 3) * 3;

        for (int k = 0; k < 9; ++k)
        {
            if (k != j && board[i][k] == board[i][j])
                return false;
            if (k != i && board[k][j] == board[i][j])
                return false;
            if ((row_offset + k / 3 != i || col_offset + k % 3 != j) && board[row_offset + k / 3][col_offset + k % 3] == board[i][j])
                return false;
        }

        return true;
    }

    bool isValidSudoku(vector<vector<char>> &board)
    {
        for (int i = 0; i < 9; ++i)
        {
            for (int j = 0; j < 9; ++j)
            {
                if (board[i][j] != '.')
                {
                    if (!validateUtil(board, i, j))
                        return false;
                }
            }
        }

        return true;
    }
};