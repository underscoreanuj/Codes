#include <iostream>
#include <vector>

#define ll long long int

using namespace std;

bool isSpecial(ll n)
{
    return n & (n << 1);
}

int main()
{
    ll n = 0, q = 0, l = 0, r = 0, count = 0;
    cin >> n >> q;

    vector<int> a(n, 0);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }

    while (q--)
    {
        cin >> l >> r;
        count = 0;

        for (int i = l - 1; i < r; ++i)
        {
            if (isSpecial(a[i]))
                ++count;
        }

        cout << count << "\n";
    }

    return 0;
}

auto speedup = []() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();