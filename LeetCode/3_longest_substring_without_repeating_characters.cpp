class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        if (s.length() == 0)
            return 0;

        unordered_set<char> H;
        int i = 0, j = 0, n = s.length(), max_len = 0;

        while (i < n)
        {
            if (H.find(s[i]) == H.end())
            {
                H.insert(s[i]);
                ++i;
                max_len = max(max_len, i - j);
            }
            else
            {
                H.erase(s[j]);
                ++j;
            }
        }

        return max_len;
    }
};