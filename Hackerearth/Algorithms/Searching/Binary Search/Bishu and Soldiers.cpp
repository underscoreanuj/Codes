#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n = 0, p = 0, q = 0, idx = 0;

    cin >> n;
    vector<int> a(n, 0);
    vector<int> preSum(n, 0);

    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }

    sort(a.begin(), a.end());
    preSum[0] = a[0];
    for (int i = 1; i < n; ++i)
    {
        preSum[i] = a[i] + preSum[i - 1];
    }

    cin >> q;
    while (q--)
    {
        cin >> p;
        idx = upper_bound(a.begin(), a.end(), p) - a.begin();
        if (idx > 0)
            cout << idx << " " << preSum[idx - 1] << "\n";
        else
            cout << "0 0\n";
    }

    return 0;
}