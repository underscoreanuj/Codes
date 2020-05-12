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