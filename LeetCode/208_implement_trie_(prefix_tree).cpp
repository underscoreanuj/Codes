class Trie
{
public:
    /** Initialize your data structure here. */
    bool isWord;
    Trie *children[26];

    Trie()
    {
        this->isWord = false;
        memset(this->children, NULL, sizeof(this->children));
    }

    /** Inserts a word into the trie. */
    void insert(string word)
    {
        Trie *cur = this;
        int idx = -1;

        for (int i = 0; i < word.length(); ++i)
        {
            idx = word[i] - 'a';
            if (cur->children[idx] == NULL)
            {
                cur->children[idx] = new Trie();
            }
            cur = cur->children[idx];
        }

        cur->isWord = true;
    }

    /** Returns if the word is in the trie. */
    bool search(string word, bool checkEnd = true)
    {
        Trie *cur = this;
        int idx = -1;

        for (int i = 0; i < word.length(); ++i)
        {
            idx = word[i] - 'a';
            if (cur->children[idx] == NULL)
            {
                return false;
            }
            cur = cur->children[idx];
        }

        return cur->isWord || !checkEnd;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix)
    {
        return this->search(prefix, false);
    }
};

auto speedup = []() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */