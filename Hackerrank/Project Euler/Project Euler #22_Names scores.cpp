#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;

int calculate_score(string &name, int rank)
{
    int score = 0;
    for (char c : name)
    {
        score += (int(c) - int('A') + 1);
    }

    return score * rank;
}

int main()
{
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n = 0, q = 0;
    cin >> n;

    vector<string> names;
    unordered_map<string, int> scores;
    string input;
    for (int i = 0; i < n; ++i)
    {
        cin >> input;
        names.emplace_back(input);
    }

    sort(names.begin(), names.end());
    for (int i = 0; i < n; ++i)
    {
        scores[names[i]] = calculate_score(names[i], i + 1);
    }

    cin >> q;

    while (q--)
    {
        cin >> input;
        cout << scores[input] << "\n";
    }

    return 0;
}
