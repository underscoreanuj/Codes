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

// recursive solution with memoization

class Solution
{
public:
    vector<vector<int>> MEM;

    int minDistanceUtil(string &word1, string &word2, int idx1 = 0, int idx2 = 0)
    {
        if (idx1 == word1.length())
            return word2.length() - idx2;
        if (idx2 == word2.length())
            return word1.length() - idx1;

        if (MEM[idx1][idx2] > 0)
            return MEM[idx1][idx2];

        int result = 0;

        if (word1[idx1] != word2[idx2])
        {
            result = 1 + min(min(
                                 minDistanceUtil(word1, word2, idx1, idx2 + 1), // insert a char in word1
                                 minDistanceUtil(word1, word2, idx1 + 1, idx2)  // delete a char from word1
                                 ),
                             minDistanceUtil(word1, word2, idx1 + 1, idx2 + 1) // replace a char in word1
                         );
        }
        else
            result = minDistanceUtil(word1, word2, idx1 + 1, idx2 + 1);

        MEM[idx1][idx2] = result;

        return result;
    }

    int minDistance(string word1, string word2)
    {
        MEM = vector<vector<int>>(word1.size() + 1, vector<int>(word2.size() + 1, -1));

        return minDistanceUtil(word1, word2);
    }
};