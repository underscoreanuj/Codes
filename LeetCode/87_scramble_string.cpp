// efficient recursive solution with memoization

class Solution
{
public:
    vector<vector<vector<int>>> MEM;

    bool isScrambleUtil(string &s1, string &s2, int i1, int i2, int len)
    {
        if (len == 1)
            return s1[i1] == s2[i2];
        if (MEM[i1][i2][len] != -1)
            return MEM[i1][i2][len];

        for (int i = 1; i < len; ++i)
        {
            if (isScrambleUtil(s1, s2, i1, i2, i) && isScrambleUtil(s1, s2, i1 + i, i2 + i, len - i))
            {
                MEM[i1][i2][len] = 1;
                return true;
            }
            if (isScrambleUtil(s1, s2, i1, i2 + len - i, i) && isScrambleUtil(s1, s2, i1 + i, i2, len - i))
            {
                MEM[i1][i2][len] = 1;
                return true;
            }
        }

        MEM[i1][i2][len] = 0;
        return false;
    }

    bool isScramble(string s1, string s2)
    {
        if (s1.length() != s2.length())
            return false;

        MEM = vector<vector<vector<int>>>(s1.length(), vector<vector<int>>(s1.length(), vector<int>(s1.length() + 1, -1)));

        return isScrambleUtil(s1, s2, 0, 0, s1.length());
    }
};

auto speedup = []() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

// recursive solution with memoization

class Solution
{
public:
    bool isScrambleUtil(string s1, string s2, unordered_map<string, bool> &MEM)
    {
        if (s1.length() == 0)
            return true;
        if (s1.length() == 1)
            return s1 == s2;
        if (s1 == s2)
            return true;
        int len = s1.length();

        if (MEM.count(s1 + s2))
            return MEM[s1 + s2];

        for (int i = 1; i < len; ++i)
        {
            if (isScrambleUtil(s1.substr(0, i), s2.substr(0, i), MEM) && isScrambleUtil(s1.substr(i), s2.substr(i), MEM))
            {
                MEM[s1 + s2] = true;
                return true;
            }
            if (isScrambleUtil(s1.substr(0, i), s2.substr(len - i), MEM) && isScrambleUtil(s1.substr(i), s2.substr(0, len - i), MEM))
            {
                MEM[s1 + s2] = true;
                return true;
            }
        }

        MEM[s1 + s2] = false;
        return false;
    }

    bool isScramble(string s1, string s2)
    {
        if (s1.length() != s2.length())
            return false;
        unordered_map<string, bool> MEM;

        return isScrambleUtil(s1, s2, MEM);
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
    bool isScramble(string s1, string s2)
    {
        if (s1.length() != s2.length())
            return false;

        int len = s1.length();
        vector<vector<vector<bool>>> MEM(len, vector<vector<bool>>(len, vector<bool>(len + 1, false)));

        for (int k = 1; k <= len; ++k)
        {
            for (int i = len - k; i >= 0; --i)
            {
                for (int j = len - k; j >= 0; --j)
                {
                    if (k == 1)
                    {
                        MEM[i][j][k] = s1[i] == s2[j];
                    }
                    else
                    {
                        for (int q = 1; q < k; ++q)
                        {
                            if ((MEM[i][j][q] && MEM[i + q][j + q][k - q]) || (MEM[i][j + k - q][q] && MEM[i + q][j][k - q]))
                            {
                                MEM[i][j][k] = true;
                                break;
                            }
                        }
                    }
                }
            }
        }

        return MEM[0][0][len];
    }
};

auto speedup = []() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();
