#include <bits/stdc++.h>

using namespace std;

int countOccurrences(string s, string c, string next = "", bool checkNext = false)
{
    int count = 0;
    size_t pos = 0, cur = 0;

    pos = s.find(c, cur);

    while (pos != string::npos)
    {
        if (!checkNext || s.substr(pos + c.length(), next.length()) != next)
            ++count;
        cur = pos + c.length();
        pos = s.find(c, cur);
    }

    return count;
}

int main()
{
    int t = 0;
    string s;
    cin >> t;

    while (t--)
    {
        cin >> s;
        cout << "SUVO = " << countOccurrences(s, "SUVO", "JIT", true) << ", SUVOJIT = " << countOccurrences(s, "SUVOJIT") << "\n";
    }

    return 0;
}