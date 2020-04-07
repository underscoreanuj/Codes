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