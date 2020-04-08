// recursive solution with memoization

class Solution
{
public:
    unordered_map<string, bool> MEM;

    bool wordBreakUtil(string s, unordered_set<string> &wDict)
    {
        if (s.length() == 0)
            return true;
        if (wDict.count(s) > 0)
            return true;
        if (MEM.count(s) > 0)
            return MEM[s];

        for (int i = 1; i < s.length(); ++i)
        {
            if (wDict.count(s.substr(0, i)) > 0)
            {
                if (wordBreakUtil(s.substr(i, s.length() - i), wDict))
                {
                    MEM[s] = true;
                    return true;
                }
            }
        }

        MEM[s] = false;
        return false;
    }

    bool wordBreak(string s, vector<string> &wordDict)
    {
        unordered_set<string> wDict(wordDict.begin(), wordDict.end());

        return wordBreakUtil(s, wDict);
    }
};

// iterative solution with DP

class Solution
{
public:
    bool wordBreak(string s, vector<string> &wordDict)
    {
        unordered_set<string> wDict(wordDict.begin(), wordDict.end());
        vector<bool> tab(s.size() + 1, false);

        // empty string can be created by wordDict
        tab[0] = true;

        for (int i = 1; i <= s.size(); ++i)
        {
            for (int j = i - 1; j >= 0; --j)
            {
                if (tab[j])
                {
                    if (wDict.count(s.substr(j, i - j)) > 0)
                    {
                        tab[i] = true;
                        break;
                    }
                }
            }
        }

        return tab[s.size()];
    }
};