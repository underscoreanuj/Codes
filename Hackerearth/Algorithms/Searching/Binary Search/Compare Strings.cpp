#include <bits/stdc++.h>

using namespace std;

auto speedup = []() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

int main()
{
    int n = 0, q = 0, x = 0;

    string a, b;

    cin >> n >> q;
    cin >> a >> b;

    if (b >= a)
    {
        while (q--)
            cout << "YES\n";
        return 0;
    }

    int ct_a = 0, ct_b = 0;

    for (int i = 0; i < n; ++i)
    {
        if (a[i] == '1')
            ct_a += (i + 1);
        if (b[i] == '1')
            ct_b += (i + 1);
    }

    while (q--)
    {
        cin >> x;
        if (b[x - 1] == '0')
        {
            ct_b += x;
            b[x - 1] == '1';
        }

        if (ct_b >= ct_a)
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}