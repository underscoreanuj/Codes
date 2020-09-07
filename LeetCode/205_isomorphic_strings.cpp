class Solution
{
public:
    bool isIsomorphic(string s, string t)
    {
        vector<int> m1(128, -1), m2(128, -1);

        if (s.length() != t.length())
            return false;

        for (int i = 0; i < s.length(); ++i)
        {
            if (m1[s[i]] == -1)
                m1[s[i]] = i;
            if (m2[t[i]] == -1)
                m2[t[i]] = i;

            if (m1[s[i]] != m2[t[i]])
                return false;
        }

        return true;
    }
};

auto speedup = []() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();