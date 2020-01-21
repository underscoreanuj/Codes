#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

int main()
{

    unordered_map<char, int> Points = {
        {'e', 1}, {'a', 1}, {'i', 1}, {'o', 1}, {'n', 1}, {'r', 1}, {'t', 1}, {'l', 1}, {'s', 1}, {'u', 1}, {'d', 2}, {'g', 2}, {'b', 3}, {'c', 3}, {'m', 3}, {'p', 3}, {'f', 4}, {'h', 4}, {'v', 4}, {'w', 4}, {'y', 4}, {'k', 5}, {'j', 8}, {'x', 8}, {'q', 10}, {'z', 10}};

    unordered_map<char, int> available;
    vector<string> words;

    int N;
    cin >> N;
    cin.ignore();
    for (int i = 0; i < N; i++)
    {
        string W;
        getline(cin, W);
        words.push_back(W);
    }
    string LETTERS;
    getline(cin, LETTERS);

    for (auto c : LETTERS)
        ++available[c];

    int max_ct = -1, ct = 0;

    unordered_map<char, int> t_available = available;

    string op;
    for (int i = 0; i < words.size(); ++i)
    {
        ct = 0;
        t_available = available;
        for (int j = 0; j < words[i].length(); ++j)
        {
            if (t_available[words[i][j]] > 0)
            {
                ct += Points[words[i][j]];
                --t_available[words[i][j]];
            }
            else
            {
                ct = -1;
                break;
            }
        }

        if (max_ct < ct)
        {
            max_ct = ct;
            op = words[i];
        }
    }

    cout << op << endl;
}