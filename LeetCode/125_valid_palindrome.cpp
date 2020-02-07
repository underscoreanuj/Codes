class Solution
{
public:
    bool isPalindrome(string s)
    {
        if (s.length() == 0)
            return true;

        int l = 0, r = s.length() - 1;
        while (l <= r)
        {
            while (l < s.length() - 1 && !isalnum(s[l]))
                ++l;
            while (r > 0 && !isalnum(s[r]))
                --r;
            if (l <= r)
                if (tolower(s[l]) != tolower(s[r]))
                    return false;
            ++l;
            --r;
        }

        return true;
    }
};