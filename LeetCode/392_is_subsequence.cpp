class Solution
{
public:
    bool isSubsequence(string s, string t)
    {
        if (s == t || s.length() == 0)
            return true;
        if (t.length() == 0)
            return false;

        int i = 0, j = 0;

        while (j < t.length())
        {
            if (s[i] == t[j])
                ++i;
            ++j;

            if (i == s.length())
                return true;
        }

        return false;
    }
};

auto speedup = []() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();