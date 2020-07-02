class Solution
{
public:
    void transposeMatrix(vector<vector<int>> &matrix)
    {
        for (int i = 0; i < matrix.size(); ++i)
        {
            for (int j = i + 1; j < matrix[i].size(); ++j)
            {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
    }

    void rotateRows(vector<vector<int>> &matrix)
    {
        for (int i = 0; i < matrix.size(); ++i)
            reverse(matrix[i].begin(), matrix[i].end());
    }

    void rotate(vector<vector<int>> &matrix)
    {
        transposeMatrix(matrix);
        rotateRows(matrix);
    }
};