class Solution
{
public:
    int lengthOfLastWord(string s)
    {
        if (s.length() == 0)
            return 0;

        int endIdx = s.length() - 1;
        while (endIdx > 0 && s[endIdx] == ' ')
            --endIdx;

        if (s[endIdx] == ' ')
            return 0;
        if (endIdx == 0 && s[endIdx] != ' ')
            return 1;

        int startIdx = endIdx - 1;
        while (startIdx > 0 && s[startIdx] != ' ')
            --startIdx;

        return endIdx - startIdx + (s[startIdx] == ' ' ? 0 : 1);
    }
};