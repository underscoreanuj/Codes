class Solution
{
public:
    string getActualString(string s)
    {
        string result = "";
        int backspace_count = 0;
        for (int i = s.length() - 1; i >= 0; --i)
        {
            if (s[i] == '#')
            {
                ++backspace_count;
            }
            else
            {
                if (backspace_count == 0)
                {
                    result += s[i];
                }
                else
                    --backspace_count;
            }
        }

        return result;
    }

    bool backspaceCompare(string S, string T)
    {
        return getActualString(S) == getActualString(T);
    }
};