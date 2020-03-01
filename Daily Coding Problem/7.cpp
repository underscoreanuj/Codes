/*
 *
 * Good morning! Here's your coding interview problem for today.
 * This problem was asked by Facebook.
 * Given the mapping a = 1, b = 2, ... z = 26, and an encoded message, count the number of ways it can be decoded.
 * For example, the message '111' would give 3, since it could be decoded as 'aaa', 'ka', and 'ak'.
 * You can assume that the messages are decodable. For example, '001' is not allowed.
 * 
 * 
 * Online Judge: https://leetcode.com/problems/decode-ways/
 * 
*/

// recursive approach with memoization

class Solution
{
public:
    int numDecodingsUtil(string s, int idx, vector<int> &MEM)
    {
        if (idx >= s.length())
            return 1;
        if (MEM[idx] != -1)
            return MEM[idx];
        if (s[idx] == '0')
            return 0;

        int res = numDecodingsUtil(s, idx + 1, MEM);
        if (idx + 1 < s.length() && (s[idx] == '1' || (s[idx] == '2' && s[idx + 1] < '7')))
        {
            res += numDecodingsUtil(s, idx + 2, MEM);
        }

        MEM[idx] = res;
        return res;
    }

    int numDecodings(string s)
    {
        if (s.length() == 0)
            return 0;
        vector<int> MEM(s.length(), -1);
        return numDecodingsUtil(s, 0, MEM);
    }
};

// iterative approach using dynamic programming (more space efficient)

class Solution
{
public:
    int numDecodings(string s)
    {
        if (s.length() == 0)
            return 0;
        int n = s.length();
        vector<int> MEM(n + 1, 0);
        MEM[n] = 1;

        for (int i = n - 1; i >= 0; --i)
        {
            if (s[i] != '0')
            {
                MEM[i] = MEM[i + 1];
                if (i + 1 < n && (s[i] == '1' || (s[i] == '2' && s[i + 1] < '7')))
                    MEM[i] += MEM[i + 2];
            }
            else
                MEM[i] = 0;
        }

        return MEM[0];
    }
};
