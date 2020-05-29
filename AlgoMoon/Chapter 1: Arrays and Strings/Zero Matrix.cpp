vector<vector<int>> zeroMatrix(vector<vector<int>> matrix)
{

    bool first_row = false, first_col = false;

    for (int i = 0; i < matrix.size(); ++i)
    {

        for (int j = 0; j < matrix[i].size(); ++j)
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

    for (int i = 1; i < matrix.size(); ++i)
    {

        for (int j = 1; j < matrix[i].size(); ++j)
        {

            if (matrix[i][0] == 0 || matrix[0][j] == 0)

                matrix[i][j] = 0;
        }
    }

    if (first_row)
        fill(matrix[0].begin(), matrix[0].end(), 0);

    if (first_col)
        for (int i = 0; i < matrix.size(); ++i)
            matrix[i][0] = 0;

    return matrix;
}
