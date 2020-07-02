#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t = 0, q = 0, x = 0, pos = 0;
    cin >> t;
    vector<long long int> transactions(t, 0);
    cin >> transactions[0];

    for (int i = 1; i < t; ++i)
    {
        cin >> x;
        transactions[i] = x + transactions[i - 1];
    }

    cin >> q;

    while (q--)
    {
        cin >> x;
        pos = (lower_bound(transactions.begin(), transactions.end(), x) - transactions.begin());
        if (pos == t)
            cout << "-1\n";
        else
            cout << (pos + 1) << "\n";
    }

    return 0;
}