#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

bool isPunct(char c)
{
    return !isalnum(c) && c != ' ';
}

string removeExtraSpaces(string s)
{
    string ret;
    int n = s.length();
    int i = 0;
    while (i < n)
    {
        if (s[i] == ' ')
        {
            while (i < n && s[i] == ' ')
                ++i;
            if (!isPunct(s[i]))
                ret += " ";
        }
        if (i < n)
            ret += s[i];
        ++i;
    }

    return ret;
}

string putSpaces(string s)
{
    string ret;
    int n = s.length();
    int i = 0;
    while (i < n)
    {
        if (isPunct(s[i]))
        {
            ret += s[i];
            if (i + 1 < n && s[i + 1] != ' ')
                ret += " ";
            ++i;
        }
        if (i < n)
            ret += s[i];
        ++i;
    }

    return ret;
}

string removeExtraPuncts(string s)
{
    string ret;
    int n = s.length();
    int i = 0;
    while (i < n)
    {
        if (isPunct(s[i]))
        {
            ret += s[i];
            while (i < n && isPunct(s[i]))
                ++i;
        }
        if (i < n)
            ret += s[i];
        ++i;
    }

    return ret;
}

string capitalize(string s)
{
    string ret;
    int n = s.length();
    int i = 0;

    for (int j = 0; j < n; ++j)
        s[j] = tolower(s[j]);

    while (i < n)
    {
        if (s[i] == '.')
        {
            if (i + 2 < n)
                s[i + 2] = toupper(s[i + 2]);
        }
        ret += s[i];
        ++i;
    }
    ret[0] = toupper(ret[0]);

    return ret;
}

int main()
{
    string intext;
    getline(cin, intext);

    string result = removeExtraSpaces(intext);
    result = removeExtraPuncts(result);
    result = putSpaces(result);
    result = capitalize(result);

    cout << result << "\n";
}