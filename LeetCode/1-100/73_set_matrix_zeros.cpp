class Solution
{
public:
    void setZeroes(vector<vector<int>> &matrix)
    {
        bool first_row = false, first_col = false;
        int i = 0, j = 0, k = 0;
        for (i = 0; i < matrix.size(); ++i)
        {
            for (j = 0; j < matrix[0].size(); ++j)
            {
                if (matrix[i][j] == 0)
                {
                    if (i == 0)
                        first_row = true;
                    if (j == 0)
                        first_col = true;
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        for (i = 1; i < matrix.size(); ++i)
            for (j = 1; j < matrix[0].size(); ++j)
                if (matrix[i][0] == 0 || matrix[0][j] == 0)
                    matrix[i][j] = 0;

        if (first_row)
            for (i = 0; i < matrix[0].size(); ++i)
                matrix[0][i] = 0;
        if (first_col)
            for (i = 0; i < matrix.size(); ++i)
                matrix[i][0] = 0;
    }
};