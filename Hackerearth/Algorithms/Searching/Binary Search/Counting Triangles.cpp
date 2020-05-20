#include <bits/stdc++.h>

using namespace std;

#define ll long long

auto speedup = []() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class MyHash
{
public:
    size_t operator()(const array<ll, 3> &o) const
    {
        return (hash<ll>()(o[0]) ^ hash<ll>()(o[1]) ^ hash<ll>()(o[2]));
    }
};

int main()
{
    int n = 0, ct = 0;

    array<ll, 3> input;
    unordered_map<array<ll, 3>, int, MyHash> MEM;

    cin >> n;

    for (int i = 0; i < n; ++i)
    {
        cin >> input[0] >> input[1] >> input[2];
        sort(input.begin(), input.end());

        ++MEM[input];
    }

    for (auto e : MEM)
    {
        if (e.second == 1)
            ++ct;
    }

    cout << ct;

    return 0;
}