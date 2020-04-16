// without stack solution

class Solution
{
public:
    bool checkValidString(string s)
    {
        int l = 0, h = 0;

        for (char &c : s)
        {
            if (c == '(')
            {
                ++l;
                ++h;
            }
            else if (c == ')')
            {
                --l;
                --h;
            }
            else
            {
                --l;
                ++h;
            }

            if (h < 0)
                return false;
            if (l < 0)
                l = 0;
        }

        return l == 0;
    }
};

// two stack solution

class Solution
{
public:
    bool checkValidString(string s)
    {
        stack<int> paren, aster;

        for (int i = 0; i < s.length(); ++i)
        {
            if (s[i] == '(')
                paren.push(i);
            else if (s[i] == '*')
                aster.push(i);
            else
            {
                if (paren.empty())
                {
                    if (aster.empty())
                        return false;
                    aster.pop();
                }
                else
                {
                    paren.pop();
                }
            }
        }

        while (!paren.empty() && !aster.empty() && paren.top() < aster.top())
        {
            aster.pop();
            paren.pop();
        }

        if (!paren.empty())
            return false;

        return true;
    }
};