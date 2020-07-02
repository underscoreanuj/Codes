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
    int R;
    cin >> R;
    cin.ignore();
    int L;
    cin >> L;
    cin.ignore();

    vector<int> res, ans;
    res.push_back(R);

    while (--L)
    {
        int i = 0, ct = 0;
        while (i < res.size())
        {
            ct = 0;
            int t = res[i];
            while (i < res.size() && res[i] == t)
            {
                ++i;
                ++ct;
            }
            ans.push_back(ct);
            ans.push_back(t);
        }

        res = ans;
        ans.clear();
    }

    for (int i = 0; i < res.size(); ++i)
    {
        if (i + 1 < res.size())
            cout << res[i] << " ";
        else
            cout << res[i];
    }
}