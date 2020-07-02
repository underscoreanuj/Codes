#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

vector<string> getOptions(string clause)
{
    vector<string> ret;

    size_t cur_pos = 0;
    size_t pos = clause.find('|');

    while (pos != string::npos)
    {
        ret.push_back(clause.substr(cur_pos, pos - cur_pos));
        cur_pos = pos + 1;
        pos = clause.find('|', cur_pos);
    }

    ret.push_back(clause.substr(cur_pos, clause.length() - cur_pos));

    return ret;
}

int main()
{
    int N;
    cin >> N;
    cin.ignore();

    int ct = 0;
    vector<string> clauses;

    string completeString;

    for (int i = 0; i < N; i++)
    {
        string line;
        getline(cin, line);

        completeString += line + "\n";
    }

    for (int j = 0; j < completeString.length(); ++j)
    {
        if (completeString[j] == '(')
        {
            int next_j = completeString.find(')', j + 1);
            clauses = getOptions(completeString.substr(j + 1, next_j - j - 1));
            cout << clauses[ct % clauses.size()];
            j = next_j + 1;
            ++ct;
        }
        cout << completeString[j];
    }
    cout << "\n";
}