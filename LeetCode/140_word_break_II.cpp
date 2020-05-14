// iterative dp solution

class Solution
{
public:
    bool isPossible(string &s, unordered_set<string> &wDict)
    {
        vector<bool> tab(s.length() + 1, false);
        tab[0] = true;
        string subWord;

        for (int i = 0; i < s.length(); ++i)
        {
            for (int j = i; j >= 0; --j)
            {
                if (tab[j])
                {
                    subWord = s.substr(j, i - j + 1);
                    if (wDict.count(subWord))
                    {
                        tab[i + 1] = true;
                        break;
                    }
                }
            }
        }

        return tab[s.length()];
    }

    vector<string> wordBreak(string s, vector<string> &wordDict)
    {
        unordered_set<string> wDict(wordDict.begin(), wordDict.end());
        vector<vector<string>> tab(s.length() + 1, vector<string>(0));
        tab[0] = {""};
        string subWord;

        if (!isPossible(s, wDict))
            return {};

        for (int i = 0; i < s.length(); ++i)
        {
            for (int j = i; j >= 0; --j)
            {
                if (tab[j].size())
                {
                    subWord = s.substr(j, i - j + 1);
                    if (wDict.count(subWord))
                    {
                        for (string &s : tab[j])
                            tab[i + 1].emplace_back(s + (s.length() ? " " : "") + subWord);
                    }
                }
            }
        }

        return tab[s.length()];
    }
};

auto speedup = []() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

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