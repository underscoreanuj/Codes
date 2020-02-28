/*
 *
 * Good morning! Here's your coding interview problem for today.
 * This problem was asked by Twitter.
 * Implement an autocomplete system. That is, given a query string s and a set of all possible query strings, return all strings in the set that have s as a prefix.
 * For example, given the query string de and the set of strings [dog, deer, deal], return [deer, deal].
 * Hint: Try preprocessing the dictionary into a more efficient data structure to speed up queries.
 * 
 * 
*/

// for the sake of simplicity I'm assuming that only lowercase characters are used

#include <bits/stdc++.h>

using namespace std;

class Trie
{
    char data;
    vector<Trie *> children;
    bool isEnd;

public:
    Trie()
    {
        this->data = '*';
        this->children = vector<Trie *>(26, NULL);
        isEnd = false;
    }

    Trie(char c)
    {
        this->data = c;
        this->children = vector<Trie *>(26, NULL);
    }

    void insert(string s, int idx = 0)
    {
        if (idx == s.length())
            return;

        if (!this->children[s[idx] - 'a'])
            this->children[s[idx] - 'a'] = new Trie(s[idx]);

        if (idx == s.length() - 1)
            this->children[s[idx] - 'a']->isEnd = true;

        this->children[s[idx] - 'a']->insert(s, idx + 1);
    }

    void findpAndPrint(vector<string> &words, string s, int idx = 0)
    {
        if (idx == s.length())
        {
            this->print(words, s);
            return;
        }

        if (!this->children[s[idx] - 'a'])
            return;

        this->children[s[idx] - 'a']->findpAndPrint(words, s, idx + 1);
    }

    void print(vector<string> &words, string s = "")
    {
        if (this->isEnd && s.length() > 0)
            words.push_back(s);

        for (int i = 0; i < 26; ++i)
        {
            if (this->children[i])
                this->children[i]->print(words, s + string(1, this->children[i]->data));
        }
    }
};

int main()
{
    Trie t;
    t.insert("dog");
    t.insert("deer");
    t.insert("deal");
    t.insert("test");
    t.insert("anuj");
    t.insert("value");
    t.insert("variable");
    t.insert("apple");

    vector<string> words;

    cout << "****** Dictionary ******\n";
    t.print(words);
    if (words.size() > 0)
        for (string w : words)
            cout << w << "\n";
    else
        cout << "{Empty!!!}\n";
    cout << "************************\n";

    cout << "******** Lookup ********\n";
    words.clear();
    t.findpAndPrint(words, "de");
    if (words.size() > 0)
        for (string w : words)
            cout << w << "\n";
    else
        cout << "{No matches!!!}\n";
    cout << "************************\n";

    return 0;
}
