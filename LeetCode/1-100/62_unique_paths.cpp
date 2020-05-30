// class Solution
// {
// public:
//     int uniquePaths(int m, int n)
//     {
//         if (m <= 1 || n <= 1)
//             return 1;
//         vector<vector<int>> tab(m, vector<int>(n, 1));
//         for (int i = 1; i < m; ++i)
//             for (int j = 1; j < n; ++j)
//                 tab[i][j] = tab[i - 1][j] + tab[i][j - 1];

//         return tab[m - 1][n - 1];
//     }
// };

class Solution
{
public:
    int uniquePaths(int m, int n)
    {
        if (m <= 1 || n <= 1)
            return 1;

        --m;
        --n;
        long long int res = 1;
        if (m < n)
            swap(m, n);

        for (int i = m + 1; i <= m + n; ++i)
        {
            res *= i;
            res /= (i - m);
        }

        return res;
    }
};