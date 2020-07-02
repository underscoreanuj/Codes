// space efficient dp solution : O(m*n) time, O(n) space

class Solution
{
public:
    int maximalSquare(vector<vector<char>> &matrix)
    {
        if (matrix.empty())
            return 0;

        int m = matrix.size(), n = matrix[0].size(), result = 0, prev = 0, cur = 0;
        int tab[n];
        memset(tab, 0, sizeof(tab));

        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                cur = tab[j];
                if (matrix[i][j] == '1')
                {
                    if (i == 0 || j == 0)
                        tab[j] = 1;
                    else
                        tab[j] = min(prev, min(tab[j], tab[j - 1])) + 1;
                    result = max(result, tab[j]);
                }
                else
                    tab[j] = 0;
                prev = cur;
            }
        }

        return result * result;
    }
};

auto speedup = []() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

// dp solution : O(m*n) time, O(m*n) space

class Solution
{
public:
    int maximalSquare(vector<vector<char>> &matrix)
    {
        if (matrix.empty())
            return 0;

        int m = matrix.size(), n = matrix[0].size(), result = 0;
        int tab[m][n];

        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (matrix[i][j] == '1')
                {
                    if (i == 0 || j == 0)
                        tab[i][j] = 1;
                    else
                        tab[i][j] = min(tab[i - 1][j - 1], min(tab[i - 1][j], tab[i][j - 1])) + 1;
                    result = max(result, tab[i][j]);
                }
                else
                    tab[i][j] = 0;
            }
        }

        return result * result;
    }
};

auto speedup = []() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

// brute force : O((m*n)^2) time, O(1) space

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