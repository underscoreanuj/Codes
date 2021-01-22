class Solution
{
public:
    bool closeStrings(string word1, string word2)
    {
        if (word1.length() != word2.length())
            return false;

        vector<int> freq1(26, 0), freq2(26, 0), word_count1(26, 0), word_count2(26, 0);

        for (int i = 0; i < word1.size(); ++i)
        {
            freq1[word1[i] - 'a']++;
            freq2[word2[i] - 'a']++;
            word_count1[word1[i] - 'a'] = 1;
            word_count2[word2[i] - 'a'] = 1;
        }

        sort(freq1.begin(), freq1.end());
        sort(freq2.begin(), freq2.end());

        return word_count1 == word_count2 && freq1 == freq2;
    }
};

auto speedup = []() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();