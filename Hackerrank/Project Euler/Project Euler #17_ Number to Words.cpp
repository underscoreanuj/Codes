#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

#define ll long long int

unordered_map<ll, string> M = {
    {1, "One"}, {2, "Two"}, {3, "Three"}, {4, "Four"}, {5, "Five"}, {6, "Six"}, {7, "Seven"}, {8, "Eight"}, {9, "Nine"}, {10, "Ten"}, {11, "Eleven"}, {12, "Twelve"}, {13, "Thirteen"}, {14, "Fourteen"}, {15, "Fifteen"}, {16, "Sixteen"}, {17, "Seventeen"}, {18, "Eighteen"}, {19, "Nineteen"}, {20, "Twenty"}, {30, "Thirty"}, {40, "Forty"}, {50, "Fifty"}, {60, "Sixty"}, {70, "Seventy"}, {80, "Eighty"}, {90, "Ninety"}, {100, "Hundred"}};

unordered_map<int, string> Level{
    {0, ""}, {1, "Thousand"}, {2, "Million"}, {3, "Billion"}, {4, "Trillion"}};

string getNumeralUtil(ll n)
{
    if (n == 0)
        return "";
    if (n < 100 && M.count(n))
        return M[n];

    string result = "";

    int hundreds = n / 100;
    n %= 100;
    int tens = n / 10;
    n %= 10;
    int ones = n;

    if (hundreds)
        result += M[hundreds] + " Hundred";
    if (10 * tens + ones < 21)
    {
        if (hundreds)
            result += " ";
        result += M[10 * tens + ones];
    }
    else
    {
        if (tens)
        {
            if (hundreds)
                result += " ";
            result += M[10 * tens];
        }
        if (ones)
        {
            if (hundreds || tens)
                result += " ";
            result += M[ones];
        }
    }

    return result;
}

string getNumeral(ll n)
{
    int lvl = 0;
    string result = "";
    string tmp;
    while (n)
    {
        tmp = getNumeralUtil(n % 1000);
        if (tmp.length())
            result = tmp + " " + Level[lvl] + " " + result;
        n /= 1000;
        ++lvl;
    }

    int i = result.length() - 1;
    while (result[i] == ' ')
        --i;

    result = result.substr(0, i + 1);

    i = 0;
    while (result[i] == ' ')
        ++i;

    return result.substr(i);
}

int main()
{
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */

    ll t = 0, n = 0;
    cin >> t;

    while (t--)
    {
        cin >> n;
        if (n == 0)
            cout << "Zero\n";
        else
            cout << getNumeral(n) << "\n";
    }

    return 0;
}
