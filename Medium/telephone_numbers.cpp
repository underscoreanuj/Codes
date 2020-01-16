#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

// class Trie {
// public:
//     char c;
//     vector<Trie*> children;
//     Trie(char c) {
//         this->c = c;
//         this->children = vector<Trie*>(10, NULL);
//     }
// };

// Trie* getNode(char c) {
//     Trie* ret = new Trie(c);
//     return ret;
// }

// Trie* insert(Trie* head, string s) {
//     Trie* t = head;

//     int i=0;
//     while(i < s.length() && t->children[s[i]-'0'] != NULL) {
//         t = t->children[s[i]-'0'];
//         ++i;
//     }
//     while(i<s.length()) {
//         t->children[s[i]-'0'] = getNode(s[i]);
//         t = t->children[s[i]-'0'];
//         ++i;
//     }

//     return head;
// }

// int count(Trie* head) {
//     int ret = 1;
//     for(int i=0; i<10; ++i) {
//         if(head->children[i] != NULL) {
//             ret += count(head->children[i]);
//         }
//     }
//     return ret;
// }

int main()
{
    int N;
    cin >> N;
    cin.ignore();
    unordered_set<string> NUM;

    // Trie* head = getNode('*');

    for (int i = 0; i < N; i++)
    {
        string telephone;
        cin >> telephone;
        cin.ignore();

        for (int j = 1; j <= telephone.size(); ++j)
        {
            NUM.insert(telephone.substr(0, j));
        }

        // head = insert(head, telephone);
    }

    // The number of elements (referencing a number) stored in the structure.
    // cout << count(head)-1 << endl;
    cout << NUM.size() << endl;
}