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
        this->data = '*';                          // represents the root
        this->children = vector<Trie *>(26, NULL); // 26 children to store all the possible lowercase characters [a-z]
        this->isEnd = false;                       // signifies the end of a valid word
    }

    // initialize a new node with the given character data
    Trie(char c)
    {
        this->data = c;
        this->children = vector<Trie *>(26, NULL);
        this->isEnd = false;
    }

    // insert a string s into the trie
    void insert(string s, int idx = 0)
    {
        if (idx == s.length())
            return;

        if (!this->children[s[idx] - 'a'])                   // check if a node for current character does not exists
            this->children[s[idx] - 'a'] = new Trie(s[idx]); // create a new one if true

        if (idx == s.length() - 1)                      // if this is the last character of the word mark isEnd to be true
            this->children[s[idx] - 'a']->isEnd = true; // signifies a valid end of word

        this->children[s[idx] - 'a']->insert(s, idx + 1); // insert the next character to the children of the current character
    }

    // store all children of current node in words vector
    void print(vector<string> &words, string s = "")
    {
        if (this->isEnd && s.length() > 0) // is a valid word
            words.push_back(s);

        // iterate over all children
        for (int i = 0; i < 26; ++i)
        {
            if (this->children[i]) // if a valid node is present look down the next level
                this->children[i]->print(words, s + string(1, this->children[i]->data));
        }
    }

    // lookup for the given string and store all its children in words vector by using print() as a subroutine
    void findpAndPrint(vector<string> &words, string s, int idx = 0)
    {
        if (idx == s.length()) // prefix match, now look at all the sub tries
        {
            this->print(words, s); // store all sub tries of the current node in words vector (all prefix matches)
            return;
        }

        if (!this->children[s[idx] - 'a']) // character of given string not present, no prefix matches
            return;

        this->children[s[idx] - 'a']->findpAndPrint(words, s, idx + 1); // look at the next level for the next character
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
