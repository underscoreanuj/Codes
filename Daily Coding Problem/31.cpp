/**
 * 
 * Good morning! Here's your coding interview problem for today.
 * This problem was asked by Google.
 * The edit distance between two strings refers to the minimum number of character insertions, deletions, and substitutions required to change one string to the other. For example, the edit distance between “kitten” and “sitting” is three: substitute the “k” for “s”, substitute the “e” for “i”, and append a “g”.
 * Given two strings, compute the edit distance between them.
 *
 * 
 * Online Judge: https://leetcode.com/problems/edit-distance/
 * 
 */

class Solution
{
public:
    int minDistance(string word1, string word2)
    {
        int m = word1.length(), n = word2.length();
        if (m == 0)
            return n;
        if (n == 0)
            return m;

        vector<vector<int>> tab(m + 1, vector<int>(n + 1, 0));

        for (int i = 1; i <= m; ++i)
            tab[i][0] = i;
        for (int i = 1; i <= n; ++i)
            tab[0][i] = i;

        for (int i = 1; i <= m; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                if (word1[i - 1] == word2[j - 1])
                    tab[i][j] = tab[i - 1][j - 1];
                else
                    tab[i][j] = 1 + min(tab[i - 1][j - 1], min(tab[i - 1][j], tab[i][j - 1]));
            }
        }

        return tab[m][n];
    }
};