// Iterative DP solution  O(mxn) time & O(min(m, n)) space

class Solution
{
public:
    int minDistance(string word1, string word2)
    {
        if (word1.length() > word2.length())
            return minDistance(word2, word1);

        int m = word1.length(), n = word2.length();
        if (m == 0)
            return n;
        if (n == 0)
            return m;

        int tab[m + 1];
        tab[0] = 0;
        int prev = 0, tmp = 0;

        for (int i = 1; i <= m; ++i)
            tab[i] = i;

        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j <= m; ++j)
            {
                if (j == 0)
                {
                    prev = tab[j];
                    tab[j] = i + 1;
                }
                else
                {
                    tmp = tab[j];
                    if (word1[j - 1] != word2[i])
                    {
                        tab[j] = 1 + min(min(tab[j], tab[j - 1]), prev);
                    }
                    else
                    {
                        tab[j] = prev;
                    }
                    prev = tmp;
                }
            }
        }

        return tab[m];
    }
};

// Iterative DP solution  O(mxn) time & O(mxn) space

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

        int tab[m + 1][n + 1];
        tab[0][0] = 0;

        for (int i = 1; i <= n; ++i)
            tab[0][i] = i;
        for (int i = 1; i <= m; ++i)
            tab[i][0] = i;

        for (int i = 1; i <= m; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                tab[i][j] = 0;
                if (word1[i - 1] == word2[j - 1])
                    tab[i][j] = tab[i - 1][j - 1];
                else
                {
                    tab[i][j] = 1 + min(
                                        min(
                                            tab[i - 1][j], // delete a character from word1
                                            tab[i][j - 1]  // insert a character in word1
                                            ),
                                        tab[i - 1][j - 1] // replace a character in word1
                                    );
                }
            }
        }

        return tab[m][n];
    }
};

// brute-force recursive solution (gives TLE)

class Solution
{
public:
    int minDistance(string word1, string word2)
    {
        if (word1.length() == 0)
            return word2.length();
        if (word2.length() == 0)
            return word1.length();

        if (word1[0] != word2[0])
        {
            return min(min(
                           1 + minDistance(word1, word2.substr(1)), // insert a char in word1
                           1 + minDistance(word1.substr(1), word2)  // delete a char from word1
                           ),
                       1 + minDistance(word1.substr(1), word2.substr(1)) // replace a char in word1
            );
        }
        else
            return minDistance(word1.substr(1), word2.substr(1));
    }
};