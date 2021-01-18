// mathematical solution, constant space & time (n+4)C4

class Solution
{
public:
    int countVowelStrings(int n)
    {
        return ((n + 1) * (n + 2) * (n + 3) * (n + 4)) / 24;
    }
};

// space efficient dp solution

class Solution
{
public:
    int countVowelStrings(int n)
    {
        int a = 1, e = 1, i = 1, o = 1, u = 1;

        while (n > 1)
        {
            a = (a + e + i + o + u);
            e = (e + i + o + u);
            i = (i + o + u);
            o = (o + u);
            --n;
        }

        return a + e + i + o + u;
    }
};

// dp solution

class Solution
{
public:
    int countVowelStrings(int n)
    {
        vector<vector<int>> tab(n + 1, vector<int>(6, 0));

        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= 5; ++j)
                tab[i][j] = tab[i][j - 1] + (i > 1 ? tab[i - 1][j] : 1);

        return tab[n][5];
    }
};

// recursive solution (inefficient)

class Solution
{
public:
    void countVowelStringsUtil(int &n, int &result, int cur = 0, int sz = 0)
    {
        if (sz == n)
            ++result;
        else
            for (int i = cur; i < 5; ++i)
                countVowelStringsUtil(n, result, i, sz + 1);
    }

    int countVowelStrings(int n)
    {
        int result = 0;
        countVowelStringsUtil(n, result);

        return result;
    }
};