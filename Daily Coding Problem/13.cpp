/*
 *
 * Good morning! Here's your coding interview problem for today.
 * This problem was asked by Amazon.
 * Given an integer k and a string s, find the length of the longest substring that contains at most k distinct characters.
 * For example, given s = "abcba" and k = 2, the longest substring with k distinct characters is "bcb".
 * 
 * 
 * Online Judge: https://leetcode.com/problems/longest-substring-with-at-most-k-distinct-characters/
 * Online Judge used: https://www.lintcode.com/problem/longest-substring-with-at-most-k-distinct-characters/description
 * 
*/

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