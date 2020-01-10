#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

int main()
{

    unordered_map<char, unordered_map<string, string>> M = {
        {'x', {
                  {"F", "U"},
                  {"B", "D"},
                  {"U", "B"},
                  {"D", "F"},
                  {"L", "L"},
                  {"R", "R"},
              }},
        {'y', {
                  {"F", "L"},
                  {"B", "R"},
                  {"U", "U"},
                  {"D", "D"},
                  {"L", "B"},
                  {"R", "F"},
              }},
        {'z', {
                  {"F", "F"},
                  {"B", "B"},
                  {"U", "R"},
                  {"D", "L"},
                  {"L", "U"},
                  {"R", "D"},
              }}};

    unordered_map<char, unordered_map<string, string>> M_op = {
        {'x', {
                  {"F", "D"},
                  {"B", "U"},
                  {"U", "F"},
                  {"D", "B"},
                  {"L", "L"},
                  {"R", "R"},
              }},
        {'y', {
                  {"F", "R"},
                  {"B", "L"},
                  {"U", "U"},
                  {"D", "D"},
                  {"L", "F"},
                  {"R", "B"},
              }},
        {'z', {
                  {"F", "F"},
                  {"B", "B"},
                  {"U", "L"},
                  {"D", "R"},
                  {"L", "D"},
                  {"R", "U"},
              }}};

    string rotations;
    getline(cin, rotations);
    string face1;
    getline(cin, face1);
    string face2;
    getline(cin, face2);

    unordered_map<char, int> ct;
    for (int i = 0; i < rotations.length(); ++i)
    {
        char c = rotations[i];
        if (c == 'x' || c == 'y' || c == 'z')
        {
            if (i + 1 < rotations.length() && rotations[i + 1] == '\'')
            {
                face1 = M_op[c][face1];
                face2 = M_op[c][face2];
            }
            else
            {
                face1 = M[c][face1];
                face2 = M[c][face2];
            }
        }
    }

    cout << face1 << "\n"
         << face2 << "\n";
}