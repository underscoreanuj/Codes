#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t = 0, count = 0;
    string s;
    unordered_set<char> Vowels;
    Vowels.insert('A');
    Vowels.insert('E');
    Vowels.insert('I');
    Vowels.insert('O');
    Vowels.insert('U');
    Vowels.insert('a');
    Vowels.insert('e');
    Vowels.insert('i');
    Vowels.insert('o');
    Vowels.insert('u');
    cin >> t;

    while (t--)
    {
        cin >> s;
        count = 0;
        for (int i = 0; i < s.length(); ++i)
        {
            if (Vowels.find(s[i]) != Vowels.end())
                ++count;
        }
        cout << count << "\n";
    }
    return 0;
}