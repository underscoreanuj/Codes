class Solution
{
public:
    vector<int> findSubstring(string s, vector<string> &words)
    {
        if (s.length() == 0 || words.size() == 0)
            return {};

        int word_size = words[0].length();
        int window_size = word_size * words.size();
        if (window_size > s.length())
            return {};

        vector<int> ret;
        unordered_map<string, int> wordsHash, stringHash;
        for (string word : words)
            ++wordsHash[word];

        int i = 0;
        while (i + window_size <= s.length())
        {
            stringHash.clear();
            for (int j = 0; j < window_size; j += word_size)
            {
                string tt = s.substr(i + j, word_size);
                if (wordsHash.find(tt) == wordsHash.end())
                    break;
                ++stringHash[tt];
            }
            if (stringHash == wordsHash)
                ret.emplace_back(i);
            ++i;
        }

        return ret;
    }
};