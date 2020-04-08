// recursive solution with memoization

class Solution
{
public:
    unordered_map<string, vector<string>> MEM;

    vector<string> wordBreakUtil(const string s, unordered_set<string> &wDict)
    {
        if (s.length() == 0)
            return {};

        if (MEM.count(s) > 0)
            return MEM[s];

        vector<string> result;

        string subWord;
        for (int i = 1; i <= s.size(); ++i)
        {
            subWord = s.substr(0, i);
            if (wDict.count(subWord) > 0)
            {
                if (i < s.length())
                {
                    vector<string> response = wordBreakUtil(s.substr(i, s.length() - i), wDict);
                    for (string res : response)
                    {
                        result.emplace_back(subWord + " " + res);
                    }
                }
                else
                {
                    result.emplace_back(subWord);
                }
            }
        }

        MEM[s] = result;

        return result;
    }

    vector<string> wordBreak(string s, vector<string> &wordDict)
    {
        unordered_set<string> wDict(wordDict.begin(), wordDict.end());

        return wordBreakUtil(s, wDict);
    }
};