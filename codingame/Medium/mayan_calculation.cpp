#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

typedef long long ll;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

int getNumeral(const vector<vector<string>> &map, const vector<string> &S)
{
    for (int i = 0; i < 20; ++i)
        if (map[i] == S)
            return i;
    return 0;
}

vector<int> getMayan(ll num)
{
    if (num == 0)
        return {0};
    vector<int> ret;
    int rem = 0;
    while (num)
    {
        rem = num % 20;
        num /= 20;
        ret.push_back(rem);
    }
    reverse(ret.begin(), ret.end());
    return ret;
}

void printMayan(const vector<vector<string>> &map, ll num)
{
    vector<int> t = getMayan(num);
    for (int i = 0; i < t.size(); ++i)
    {
        int idx = t[i];
        for (auto ss : map[idx])
            cout << ss << "\n";
    }
}

int main()
{
    int L;
    int H;
    cin >> L >> H;
    cin.ignore();

    vector<vector<string>> map(20);

    for (int i = 0; i < H; i++)
    {
        string numeral;
        cin >> numeral;
        cin.ignore();
        for (int j = 0; j < 20; ++j)
        {
            map[j].push_back(numeral.substr(j * L, L));
        }
    }

    int S1;
    cin >> S1;
    cin.ignore();
    int digits1 = S1 / H;
    vector<vector<string>> n1(digits1);
    int j = 0;

    for (int i = 0; i < S1; i++)
    {
        string num1Line;
        cin >> num1Line;
        cin.ignore();

        n1[j / H].push_back(num1Line);
        ++j;
    }

    int S2;
    cin >> S2;
    cin.ignore();
    int digits2 = S2 / H;
    vector<vector<string>> n2(digits2);
    j = 0;

    for (int i = 0; i < S2; i++)
    {
        string num2Line;
        cin >> num2Line;
        cin.ignore();

        n2[j / H].push_back(num2Line);
        ++j;
    }

    string operation;
    cin >> operation;
    cin.ignore();

    ll o1 = 0;
    ll o2 = 0;

    for (int i = 0; i < digits1; ++i)
    {
        o1 += pow((ll)20, digits1 - i - 1) * (ll)getNumeral(map, n1[i]);
    }
    for (int i = 0; i < digits2; ++i)
    {
        o2 += pow((ll)20, digits2 - i - 1) * (ll)getNumeral(map, n2[i]);
    }

    if (operation == "+")
        printMayan(map, o1 + o2);
    if (operation == "-")
        printMayan(map, o1 - o2);
    if (operation == "*")
        printMayan(map, o1 * o2);
    if (operation == "/")
        printMayan(map, o1 / o2);
}