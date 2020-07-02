/*
 *
 * Good morning! Here's your coding interview problem for today.
 * This problem was asked by Microsoft.
 * Given a dictionary of words and a string made up of those words (no spaces), return the original sentence in a list. If there is more than one possible reconstruction, return any of them. If there is no possible reconstruction, then return null.
 * For example, given the set of words 'quick', 'brown', 'the', 'fox', and the string "thequickbrownfox", you should return ['the', 'quick', 'brown', 'fox'].
 * Given the set of words 'bed', 'bath', 'bedbath', 'and', 'beyond', and the string "bedbathandbeyond", return either ['bed', 'bath', 'and', 'beyond] or ['bedbath', 'and', 'beyond'].
 * 
 * 
 * Online Judge: https://leetcode.com/problems/word-break-ii/
 * 
 * 
*/

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
                        break; // the break ensures only one solution is taken into consideration
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