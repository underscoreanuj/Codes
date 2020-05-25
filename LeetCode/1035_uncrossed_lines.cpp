// time: O(n*m), space: O(min(n,m)) solution (longest commong subsequence)

class Solution
{
public:
    int maxUncrossedLines(vector<int> &A, vector<int> &B)
    {
        int m = A.size(), n = B.size();
        if (m > n)
            return maxUncrossedLines(B, A);

        vector<int> tab(m + 1, 0);
        int cur = 0, prev = 0;

        for (int j = 1; j <= n; ++j)
        {
            prev = 0;
            for (int i = 1; i <= m; ++i)
            {
                cur = tab[i];

                if (A[i - 1] == B[j - 1])
                    tab[i] = 1 + prev;
                else
                    tab[i] = max(tab[i], tab[i - 1]);

                prev = cur;
            }
        }

        return tab[m];
    }
};

auto speedup = []() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

// time: O(n*m), space: O(n*m) solution (longest commong subsequence)

class Solution
{
public:
    int maxUncrossedLines(vector<int> &A, vector<int> &B)
    {
        int m = A.size(), n = B.size();
        vector<vector<int>> tab(m + 1, vector<int>(n + 1, 0));

        for (int i = 1; i <= m; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                if (A[i - 1] == B[j - 1])
                    tab[i][j] = 1 + tab[i - 1][j - 1];
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