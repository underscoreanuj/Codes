#include <bits/stdc++.h>

using namespace std;

#define ll long long int

ll solve(ll n)
{
    ll result = 0;

    while (n)
    {
        if (n % 2)
            ++result;
        n >>= 1;
    }

    return result;
}

int main()
{
    ll n = 0;
    while (cin >> n)
    {
        cout << solve(n) << "\n";
    }

    return 0;
}

auto speedup = []() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();