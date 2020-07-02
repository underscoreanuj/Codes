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
        vector<bool> tab(s.length() + 1, false);
        tab[0] = true;
        string subWord;

        for (int i = 1; i <= s.length(); ++i)
        {
            for (int j = i - 1; j >= 0; --j)
            {
                if (tab[j])
                {
                    subWord = s.substr(j, i - j);
                    if (wDict.count(subWord) > 0)
                    {
                        tab[i] = true;
                        break;
                    }
                }
            }
        }

        return tab[s.length()];
    }
};

// bfs based solution (think of it as a bfs of a graph)

class Solution
{
public:
    bool wordBreak(string s, vector<string> &wordDict)
    {

        unordered_set<string> wDict(wordDict.begin(), wordDict.end());
        vector<bool> vis(s.length(), false);
        queue<int> Q;
        string subWord;
        int idx = -1;
        Q.push(0);

        while (!Q.empty())
        {
            idx = Q.front();
            Q.pop();
            if (!vis[idx])
            {
                vis[idx] = true;
                for (int i = 1; i <= s.size() - idx; ++i)
                {
                    subWord = s.substr(idx, i);
                    if (wDict.count(subWord) > 0)
                    {
                        if (idx + i == s.length())
                            return true;
                        Q.push(idx + i);
                    }
                }
            }
        }

        return false;
    }
};