#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n = 0, k = 0;

    cin >> n;
    vector<int> A(n, 0);
    vector<int> Hash(100001, 0);

    for (int i = 0; i < n; ++i)
    {
        cin >> A[i];
        ++Hash[A[i]];
    }

    cin >> k;

    for (int i = 0; i < 100001; ++i)
    {
        if (Hash[i] == k)
        {
            cout << i;
            break;
        }
    }

    return 0;
}