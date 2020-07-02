#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n = 0, D = 0, n19 = 0, n20 = 0, nOther = 0;
    cin >> n;

    string s, tmp;
    char cur;

    while (n--)
    {
        getline(cin, s);
        cur = s[0];
        istringstream SS(s);

        while (getline(SS, tmp, ' '))
        {
            if (tmp[0] >= '0' && tmp[0] <= '9')
            {
                D = stoi(tmp);
                if (D >= 1 && D <= 30)
                {
                    if (D == 19)
                        n19 += cur == 'G' ? 2 : 1;
                    else if (D == 20)
                        n20 += cur == 'G' ? 2 : 1;
                    else
                        nOther += cur == 'G' ? 2 : 1;
                }
            }
        }
    }

    if (n19 > nOther || n20 > nOther)
        cout << "Date";
    else
        cout << "No Date";

    return 0;
}