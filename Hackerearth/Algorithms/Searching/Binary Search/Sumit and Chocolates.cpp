#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n = 0, q = 0, c = 0;
    cin >> n;
    vector<int> A(n, 0);
    for (int i = 0; i < n; ++i)
    {
        cin >> A[i];
        if (i > 0)
            A[i] += A[i - 1];
    }

    cin >> q;

    while (q--)
    {
        cin >> c;
        cout << lower_bound(A.begin(), A.end(), c) - A.begin() + 1 << "\n";
    }

    return 0;
}