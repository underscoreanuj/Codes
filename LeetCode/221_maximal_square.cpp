class Solution
{
public:
    int getArea(vector<vector<char>> &matrix, int r, int c)
    {
        int offset = 1, limit = 2, result = 1;

        while (true)
        {
            if (r + offset >= matrix.size() || c + offset >= matrix[r].size())
                break;

            for (int i = c; i < c + limit; ++i)
            {
                if (matrix[r + offset][i] != '1')
                    return result * result;
            }

            for (int i = r; i < r + limit; ++i)
            {
                if (matrix[i][c + offset] != '1')
                    return result * result;
            }

            ++result;
            ++offset;
            ++limit;
        }

        return result * result;
    }

    int maximalSquare(vector<vector<char>> &matrix)
    {
        if (matrix.size() == 0 || matrix[0].size() == 0)
            return 0;

        int m = matrix.size();
        int n = matrix[0].size();

        int result = 0;

        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (matrix[i][j] == '1')
                {
                    result = max(result, getArea(matrix, i, j));
                }
            }
        }

        return result;
    }
};

auto speedup = []() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();