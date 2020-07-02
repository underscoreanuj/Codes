class Solution
{
public:
    string preProcess(string s)
    {
        string ret = "$#";
        for (auto c : s)
            ret += string(1, c) + "#";
        return ret + "@";
    }

    string postProcess(string s)
    {
        string ret;
        for (auto c : s)
            ret += c == '#' ? "" : string(1, c);
        return ret;
    }

    string longestPalindrome(string s)
    {
        if (s.length() == 0)
            return "";

        s = preProcess(s);

        int c = 0, r = 0, mir = 0, i = 1, n = s.length();
        vector<int> lp(n, 0);

        while (i < n)
        {
            mir = 2 * c - i;

            if (i < r)
                lp[i] = min(lp[mir], r - i);

            while (s[i + (1 + lp[i])] == s[i - (1 + lp[i])])
                ++lp[i];

            if (i + lp[i] > r)
            {
                c = i;
                r = i + lp[i];
            }

            ++i;
        }

        int max_ind = 0;
        for (int i = 1; i < n; ++i)
            if (lp[max_ind] < lp[i])
                max_ind = i;

        s = s.substr(max_ind - lp[max_ind], lp[max_ind] * 2 + 1);

        return postProcess(s);
    }
};