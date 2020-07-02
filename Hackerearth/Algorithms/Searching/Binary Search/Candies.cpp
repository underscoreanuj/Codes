#include <bits/stdc++.h>

using namespace std;

auto speedup = []() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

bool isValid(const string &s, const int &len, const int &k)
{
    unordered_map<char, int> mem;
    int ct = 0;
    for (int i = 0; i < len; ++i)
    {
        ++mem[s[i]];
        if (mem[s[i]] % 2 == 0)
            ct += 2;
        if (ct + 1 >= k)
            return true;
    }
    for (int i = len; i < s.length(); ++i)
    {
        if (mem[s[i - len]] % 2 == 0)
            ct -= 2;
        --mem[s[i - len]];
        ++mem[s[i]];
        if (mem[s[i]] % 2 == 0)
            ct += 2;
        if (ct + 1 >= k)
            return true;
    }
    return false;
}

int main()
{
    string s;
    cin >> s;
    int t = 0, k = 0, l = 0, r = 0, mid = 0;
    cin >> t;
    while (t--)
    {
        cin >> k;

        l = k, r = s.length();
        while (l < r)
        {
            mid = l + ((r - l) >> 1);

            if (isValid(s, mid, k))
                r = mid;
            else
                l = mid + 1;
        }
        if (isValid(s, l, k))
            cout << l << "\n";
        else
            cout << "-1\n";
    }

    return 0;
}