#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t = 0, n = 0, k = 0, count = 0, ct = 0;
    bool flag = false;
    cin >> t;

    while (t--)
    {
        count = 0;
        cin >> n >> k;
        vector<vector<char>> tab(n, vector<char>(n, 0));

        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                cin >> tab[i][j];

        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (tab[i][j] == 'P')
                {
                    flag = false;
                    //check left
                    for (int idx = max(j - k, 0); idx < j; ++idx)
                    {
                        if (tab[i][idx] == 'T')
                        {
                            flag = true;
                            tab[i][idx] = 'C';
                            ++count;
                            break;
                        }
                    }
                    if (!flag)
                    {
                        //check right
                        ct = 0;
                        for (int idx = j + 1; idx < n && ct < k; ++idx, ++ct)
                        {
                            if (tab[i][idx] == 'T')
                            {
                                tab[i][idx] = 'C';
                                ++count;
                                break;
                            }
                        }
                    }
                }
            }
        }

        cout << count << "\n";
    }

    return 0;
}