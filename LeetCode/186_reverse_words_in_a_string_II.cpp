// solved on : https://www.lintcode.com/problem/reverse-words-in-a-string-ii/description

class Solution
{
public:
    /**
     * @param str: a string
     * @return: return a string
     */
    string reverseWords(string &str)
    {
        reverse(str.begin(), str.end());

        int l = 0, r = 0;

        while (r <= str.length())
        {
            if (str[r] == ' ' || r == str.length())
            {
                reverse(str.begin() + l, str.begin() + r);
                l = r + 1;
            }
            ++r;
        }

        return str;
    }
};