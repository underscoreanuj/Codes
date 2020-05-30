// space efficient dp solution

class Solution
{
public:
    bool isInterleave(string s1, string s2, string s3)
    {
        if (s1.length() + s2.length() != s3.length())
            return false;

        int m = s1.length(), n = s2.length();
        vector<bool> tab(n + 1, false);

        for (int i = 0; i <= m; ++i)
        {
            for (int j = 0; j <= n; ++j)
            {
                if (i == 0 && j == 0)
                    tab[j] = true;
                else if (i == 0)
                    tab[j] = tab[j - 1] && s2[j - 1] == s3[j - 1];
                else if (j == 0)
                    tab[j] = tab[j] && s1[i - 1] == s3[i - 1];
                else
                    tab[j] = (tab[j] && s1[i - 1] == s3[i + j - 1]) || (tab[j - 1] && s2[j - 1] == s3[i + j - 1]);
            }
        }

        return tab[n];
    }
};

auto speedup = []() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

// dp solution

class Solution
{
public:
    bool isInterleave(string s1, string s2, string s3)
    {
        if (s1.length() + s2.length() != s3.length())
            return false;

        int m = s1.length(), n = s2.length();
        vector<vector<bool>> tab(m + 1, vector<bool>(n + 1, false));
        tab[0][0] = true;

        for (int i = 1; i <= m; ++i)
            tab[i][0] = tab[i - 1][0] && s1[i - 1] == s3[i - 1];
        for (int i = 1; i <= n; ++i)
            tab[0][i] = tab[0][i - 1] && s2[i - 1] == s3[i - 1];

        for (int i = 1; i <= m; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                tab[i][j] = (tab[i - 1][j] && s1[i - 1] == s3[i + j - 1]) || (tab[i][j - 1] && s2[j - 1] == s3[i + j - 1]);
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

// recursive memoization solution

class Solution
{
public:
    vector<vector<int>> MEM;

    bool isInterleaveUtil(string &s1, string &s2, string &s3, int i = 0, int j = 0, int k = 0)
    {
        if (MEM[i][j] != -2)
            return MEM[i][j];

        if (i == s1.length())
            return s2.substr(j) == s3.substr(k);
        if (j == s2.length())
            return s1.substr(i) == s3.substr(k);

        bool res = false;

        if (s1[i] == s3[k])
            res = res | isInterleaveUtil(s1, s2, s3, i + 1, j, k + 1);
        if (s2[j] == s3[k])
            res = res | isInterleaveUtil(s1, s2, s3, i, j + 1, k + 1);

        MEM[i][j] = res;
        return res;
    }

    bool isInterleave(string s1, string s2, string s3)
    {
        if (s1.length() + s2.length() != s3.length())
            return false;

        MEM = vector<vector<int>>(s1.length() + 1, vector<int>(s2.length() + 1, -2));

        return isInterleaveUtil(s1, s2, s3);
    }
};

auto speedup = []() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();