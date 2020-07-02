class Solution
{
public:
    string clean(string s)
    {
        int i = 0;
        while (i < s.length() && s[i] == ' ')
            ++i;
        s = s.substr(i);

        i = s.length() - 1;
        while (i >= 0 && s[i] == ' ')
            --i;
        s = s.substr(0, i + 1);

        string res;
        for (int i = 0; i < s.length(); ++i)
        {
            if (s[i] == ' ')
            {
                res += ' ';
                while (s[i] == ' ')
                    ++i;
            }
            res += s[i];
        }

        return res;
    }

    string reverseWords(string s)
    {
        s = clean(s);
        if (s.length() == 0)
            return "";
        reverse(s.begin(), s.end());
        int l = 0, r = 0;

        while (r <= s.length())
        {
            if (s[r] == ' ' || r == s.length())
            {
                reverse(s.begin() + l, s.begin() + r);
                l = r + 1;
            }
            ++r;
        }

        return s;
    }
};

auto speedup = []() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();