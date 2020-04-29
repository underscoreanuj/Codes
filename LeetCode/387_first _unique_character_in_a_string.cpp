// relativley better approach

class Solution
{
public:
    int firstUniqChar(string s)
    {
        int M[26];
        int idx[26];

        memset(M, 0, sizeof(M));
        memset(idx, 999999, sizeof(idx));

        for (int i = 0; i < s.length(); ++i)
        {
            ++M[s[i] - 'a'];
            idx[s[i] - 'a'] = i;
        }

        int result = s.length();

        for (int i = 0; i < 26; ++i)
        {
            if (M[i] == 1)
            {
                result = min(result, idx[i]);
            }
        }

        return result < s.length() ? result : -1;
    }
};

auto speedup = []() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

// simple approach

class Solution
{
public:
    int firstUniqChar(string s)
    {
        int M[26];
        memset(M, 0, sizeof(M));

        for (char &c : s)
            ++M[c - 'a'];

        for (int i = 0; i < s.length(); ++i)
            if (M[s[i] - 'a'] == 1)
                return i;

        return -1;
    }
};

auto speedup = []() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();