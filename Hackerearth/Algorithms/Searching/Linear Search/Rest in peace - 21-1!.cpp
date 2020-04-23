#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t = 0;
    string num;
    cin >> t;

    while (t--)
    {
        cin >> num;
        if (stoi(num) % 21 == 0 || num.find("21") != string::npos)
            cout << "The streak is broken!\n";
        else
            cout << "The streak lives still in our heart!\n";
    }

    return 0;
}