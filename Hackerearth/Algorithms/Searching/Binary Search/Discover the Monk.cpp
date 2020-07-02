#include <bits/stdc++.h>

using namespace std;

int binarySearch(vector<int> &A, int x)
{
    int l = 0, r = A.size() - 1, mid = 0;

    while (l <= r)
    {
        mid = l + ((r - l) >> 1);

        if (A[mid] == x)
            return mid;
        else if (A[mid] < x)
            l = mid + 1;
        else
            r = mid - 1;
    }

    return -1;
}

int main()
{
    int n = 0, q = 0, x = 0, pos = 0;
    cin >> n >> q;
    vector<int> A(n, 0);
    for (int i = 0; i < n; ++i)
        cin >> A[i];

    sort(A.begin(), A.end());

    while (q--)
    {
        cin >> x;
        pos = binarySearch(A, x);
        if (pos == -1)
            cout << "NO\n";
        else
            cout << "YES\n";
    }

    return 0;
}