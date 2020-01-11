#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

bool validateIsbnTen(string s)
{
    int prod_sum = 0;
    for (int i = 0; i < 9; ++i)
    {
        prod_sum += (s[i] - '0') * (10 - i);
    }
    int rem = prod_sum % 11;
    rem = rem == 0 ? 0 : 11 - rem;
    if (s[9] == rem + '0' || (rem == 10 && s[9] == 'X'))
        return true;

    return false;
}

bool validateIsbnThirteen(string s)
{
    int prod_sum = 0;
    for (int i = 0; i < 12; ++i)
    {
        prod_sum += (s[i] - '0') * ((i & 1) ? 3 : 1);
    }
    int rem = prod_sum % 10;
    rem = rem == 0 ? 0 : 10 - rem;
    return s[12] == rem + '0';
}

bool validate(string s)
{
    if (s.length() == 10)
        return validateIsbnTen(s);
    else if (s.length() == 13)
        return validateIsbnThirteen(s);
    return false;
}

int main()
{
    int N;
    cin >> N;
    cin.ignore();

    vector<string> invalid;

    for (int i = 0; i < N; i++)
    {
        string ISBN;
        getline(cin, ISBN);

        if (!validate(ISBN))
            invalid.push_back(ISBN);
    }

    cout << invalid.size() << " invalid:\n";
    for (auto i : invalid)
        cout << i << "\n";
}