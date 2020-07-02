class Solution
{
public:
    void makeLPS(vector<int> &lps, string s)
    {
        int i = 1, len = 0, n = s.length();
        lps[0] = 0;

        while (i < n)
        {
            if (s[i] == s[len])
            {
                ++len;
                lps[i] = len;
                ++i;
            }
            else
            {
                if (len > 0)
                    len = lps[len - 1];
                else
                {
                    lps[i] = 0;
                    ++i;
                }
            }
        }
    }

    int strStr(string haystack, string needle)
    {
        if (haystack.length() == 0)
            return needle.length() == 0 ? 0 : -1;
        if (needle.length() == 0)
            return 0;

        int h_len = haystack.length();
        int n_len = needle.length();

        vector<int> lps(n_len, 0);
        makeLPS(lps, needle);

        int i = 0, j = 0;

        while (i < h_len)
        {
            if (haystack[i] == needle[j])
            {
                ++i;
                ++j;
            }

            if (j == n_len)
                return i - j;

            if (haystack[i] != needle[j])
            {
                if (j > 0)
                    j = lps[j - 1];
                else
                    ++i;
            }
        }

        return -1;
    }
};