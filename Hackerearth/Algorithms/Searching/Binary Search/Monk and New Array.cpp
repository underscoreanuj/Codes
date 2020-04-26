#include <bits/stdc++.h>

using namespace std;

#define ll long long int

int main()
{
    ll n = 0, m = 0;
    cin >> n >> m;

    vector<vector<ll>> tab(n, vector<ll>(m, 0));

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
            cin >> tab[i][j];
        if (i > 0)
            sort(tab[i].begin(), tab[i].end());
    }

    ll min_diff = LONG_MAX;
    vector<ll>::iterator low;

    for (int i = 0; i < n - 1; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            low = lower_bound(tab[i + 1].begin(), tab[i + 1].end(), tab[i][j]);
            if (*low == tab[i][j])
            {
                cout << "0\n";
                return 0;
            }

            if (low == tab[i + 1].end())
                --low;

            min_diff = min(min_diff, abs(tab[i][j] - *low));
            if (low != tab[i + 1].begin())
                min_diff = min(min_diff, abs(tab[i][j] - *(--low)));
        }
    }

    cout << min_diff << "\n";

    return 0;
}