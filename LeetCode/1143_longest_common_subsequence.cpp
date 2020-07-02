class Solution
{
public:
    int longestCommonSubsequence(string text1, string text2)
    {
        int m = text1.length();
        int n = text2.length();

        if (m == 0 || n == 0)
            return 0;

        int tab[m + 1][n + 1];
        for (int i = 0; i <= m; ++i)
            tab[i][0] = 0;
        for (int i = 0; i <= n; ++i)
            tab[0][i] = 0;

        for (int i = 1; i <= m; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                if (text1[i - 1] == text2[j - 1])
                    tab[i][j] = tab[i - 1][j - 1] + 1;
                else
                    tab[i][j] = max(tab[i - 1][j], tab[i][j - 1]);
            }
        }

        return tab[m][n];
    }
};

auto speedup = []() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();