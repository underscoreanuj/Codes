// time: O(m*n), space: O(m*n), DP solution

class Solution
{
public:
    int countSquares(vector<vector<int>> &matrix)
    {
        int m = matrix.size(), n = matrix[0].size(), count = 0;

        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (matrix[i][j])
                {
                    if (i && j && matrix[i - 1][j] && matrix[i][j - 1] && matrix[i - 1][j - 1])
                    {
                        matrix[i][j] = 1 + min(matrix[i - 1][j - 1], min(matrix[i][j - 1], matrix[i - 1][j]));
                    }
                    count += matrix[i][j];
                }
            }
        }

        return count;
    }
};

auto speedup = []() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();