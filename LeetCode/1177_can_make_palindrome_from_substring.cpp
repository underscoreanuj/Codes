// an even better approach

class Solution
{
public:
    vector<bool> canMakePaliQueries(string s, vector<vector<int>> &queries)
    {
        vector<bool> result;
        vector<int> tab(s.length() + 1, 0);

        for (int i = 0; i < s.length(); ++i)
            tab[i + 1] = tab[i] ^ (1 << (s[i] - 'a'));

        for (auto q : queries)
            result.push_back(((bitset<26>(tab[q[1] + 1] ^ tab[q[0]]).count()) >> 1) <= q[2]);

        return result;
    }
};

auto speedup = []() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

// a better approach

class Solution
{
public:
    vector<bool> canMakePaliQueries(string s, vector<vector<int>> &queries)
    {
        if (queries.size() == 0)
            return {};

        vector<bool> result;
        vector<vector<bool>> tab(s.length() + 1, vector<bool>(26, false));
        int ct = 0;

        for (int i = 0; i < s.length(); ++i)
        {
            for (int j = 0; j < 26; ++j)
            {
                tab[i + 1][j] = tab[i][j];
            }
            tab[i + 1][s[i] - 'a'] = tab[i + 1][s[i] - 'a'] ^ true;
        }

        for (auto q : queries)
        {
            ct = 0;
            for (int i = 0; i < 26; ++i)
            {
                ct += (tab[q[1] + 1][i] ^ tab[q[0]][i]) ? 1 : 0;
            }
            result.push_back(((ct >> 1) <= q[2]));
        }

        return result;
    }
};

auto speedup = []() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

// normal approach

class Solution
{
public:
    vector<bool> canMakePaliQueries(string s, vector<vector<int>> &queries)
    {
        if (queries.size() == 0)
            return {};

        vector<bool> result;
        vector<vector<int>> tab(s.length() + 1, vector<int>(26, 0));
        int ct = 0;

        for (int i = 0; i < s.length(); ++i)
        {
            for (int j = 0; j < 26; ++j)
            {
                tab[i + 1][j] = tab[i][j];
            }
            ++tab[i + 1][s[i] - 'a'];
        }

        for (auto q : queries)
        {
            ct = 0;
            for (int i = 0; i < 26; ++i)
            {
                ct += ((tab[q[1] + 1][i] - tab[q[0]][i]) % 2);
            }
            result.push_back(((ct >> 1) <= q[2]));
        }

        return result;
    }
};

auto speedup = []() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();