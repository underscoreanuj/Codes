
// Online Judge used: https://www.lintcode.com/problem/longest-substring-with-at-most-k-distinct-characters/description

class Solution
{
public:
    /**
     * @param s: A string
     * @param k: An integer
     * @return: An integer
     */
    int lengthOfLongestSubstringKDistinct(string &s, int k)
    {
        if (s.length() == 0 || k == 0)
            return 0;
        if (k >= s.size())
            return s.size();

        unordered_map<char, int> M;
        int i = 0, j = 0, max_len = 0;

        while (i < s.size())
        {
            if (M.size() < k || M.find(s[i]) != M.end())
            {
                ++M[s[i]];
                ++i;
                max_len = max(max_len, i - j);
            }
            else
            {
                --M[s[j]];
                if (M[s[j]] == 0)
                    M.erase(s[j]);
                ++j;
            }
        }

        return max_len;
    }
};