class Solution
{
public:
    bool isOpening(char c)
    {
        return (c == '(' || c == '{' || c == '[');
    }

    char getOp(char c)
    {
        if (c == ')')
            return '(';
        if (c == '}')
            return '{';
        if (c == ']')
            return '[';
        return '-';
    }

    bool isValid(string s)
    {
        if (s.length() == 0)
            return true;
        int n = s.length();
        if (n & 1)
            return false;
        if (s[0] == ')' || s[0] == '}' || s[0] == ']')
            return false;
        if (s[n - 1] == '(' || s[n - 1] == '{' || s[n - 1] == '[')
            return false;

        stack<char> ST;
        for (int i = 0; i < n; ++i)
        {
            if (isOpening(s[i]))
                ST.push(s[i]);
            else
            {
                if (ST.empty())
                    return false;
                if (getOp(s[i]) != ST.top())
                    return false;
                else
                    ST.pop();
            }
        }

        return ST.empty();
    }
};