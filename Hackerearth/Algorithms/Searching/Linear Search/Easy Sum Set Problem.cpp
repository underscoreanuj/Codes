#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n = 0, m = 0, x = 0, y = 0;
    unordered_set<int> A, C;
    set<int> B;
    bool flag = false;

    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> x;
        A.insert(x);
    }

    cin >> m;
    for (int i = 0; i < m; ++i)
    {
        cin >> x;
        C.insert(x);
    }

    for (auto a : A)
    {
        for (auto c : C)
        {
            x = c - a;
            flag = true;
            for (auto aa : A)
            {
                y = aa + x;
                if (C.find(y) == C.end())
                {
                    flag = false;
                    break;
                }
            }
            if (flag)
                B.insert(x);
        }
    }

    for (auto b : B)
        cout << b << " ";

    return 0;
}