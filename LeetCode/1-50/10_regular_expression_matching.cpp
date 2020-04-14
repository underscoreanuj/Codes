class Solution
{
public:
    bool isMatch(string s, string p)
    {
        int s_len = s.length(), p_len = p.length();

        vector<vector<bool>> tab(s_len + 1, vector<bool>(p_len + 1, false));
        tab[0][0] = true;
        for (int i = 2; i <= p_len; ++i)
        {
            if (p[i - 1] == '*')
                tab[0][i] = tab[0][i - 2];
        }

        for (int i = 1; i <= s_len; ++i)
        {
            for (int j = 1; j <= p_len; ++j)
            {
                if (s[i - 1] == p[j - 1] || p[j - 1] == '.')
                    tab[i][j] = tab[i - 1][j - 1];
                if (p[j - 1] == '*')
                {
                    tab[i][j] = tab[i][j - 2];
                    if (s[i - 1] == p[j - 2] || p[j - 2] == '.')
                        tab[i][j] = tab[i][j] | tab[i - 1][j];
                }
            }
        }

        return tab[s_len][p_len];
    }
};