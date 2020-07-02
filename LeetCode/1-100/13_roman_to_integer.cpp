class Solution
{
public:
    int romanToInt(string s)
    {
        unordered_map<char, int> H = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000},
        };

        int ret = H[s[s.length() - 1]];
        for (int i = 0; i < s.length() - 1; ++i)
        {
            if (s[i] == 'I' && s[i + 1] == 'V')
                ret -= 1;
            else if (s[i] == 'I' && s[i + 1] == 'X')
                ret -= 1;
            else if (s[i] == 'X' && s[i + 1] == 'L')
                ret -= 10;
            else if (s[i] == 'X' && s[i + 1] == 'C')
                ret -= 10;
            else if (s[i] == 'C' && s[i + 1] == 'D')
                ret -= 100;
            else if (s[i] == 'C' && s[i + 1] == 'M')
                ret -= 100;
            else
                ret += H[s[i]];
        }

        return ret;
    }
};