class Solution
{
public:
    int longestValidParentheses(string s)
    {
        int o = 0, c = 0, longestVP = 0;
        for (int i = 0; i < s.length(); ++i)
        {
            if (s[i] == '(')
                ++o;
            if (s[i] == ')')
                ++c;
            if (c == o)
                longestVP = max(longestVP, 2 * o);
            if (c > o)
            {
                c = o = 0;
            }
        }
        c = o = 0;
        for (int i = s.length() - 1; i >= 0; --i)
        {
            if (s[i] == '(')
                ++o;
            if (s[i] == ')')
                ++c;
            if (c == o)
                longestVP = max(longestVP, 2 * o);
            if (c < o)
            {
                c = o = 0;
            }
        }

        return longestVP;
    }
};