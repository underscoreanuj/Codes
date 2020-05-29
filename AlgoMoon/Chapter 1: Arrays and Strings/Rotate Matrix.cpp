void transpose(vector<vector<int>> &matrix)
{

    for (int i = 0; i < matrix.size() - 1; ++i)
    {

        for (int j = i + 1; j < matrix[i].size(); ++j)
        {

            swap(matrix[i][j], matrix[j][i]);
        }
    }
}

void rotateRows(vector<vector<int>> &matrix)
{

    for (auto &row : matrix)
    {

        reverse(row.begin(), row.end());
    }
}

vector<vector<int>> rotateMatrix(vector<vector<int>> matrix)
{

    transpose(matrix);

    rotateRows(matrix);

    return matrix;
}
