#include <bits/stdc++.h>

using namespace std;

#define ll long long int

int binarySearch(vector<ll> &a, ll x)
{
    int l = 0, r = a.size() - 1, mid = 0;

    while (l <= r)
    {
        mid = l + ((r - l) >> 1);

        if (a[mid] == x)
            return mid;
        else if (a[mid] < x)
            l = mid + 1;
        else
            r = mid - 1;
    }

    return -1;
}

int main()
{
    ll n = 0, q = 0, x = 0;
    cin >> n;
    vector<ll> A(n, 0);

    for (int i = 0; i < n; ++i)
    {
        cin >> A[i];
    }

    sort(A.begin(), A.end());

    cin >> q;

    while (q--)
    {
        cin >> x;
        cout << binarySearch(A, x) + 1 << "\n";
    }

    return 0;
}