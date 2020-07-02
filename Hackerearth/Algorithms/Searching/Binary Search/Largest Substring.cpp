#include <bits/stdc++.h>

using namespace std;

auto speedup = []() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

inline int getMaxLen(const string &s)
{
    int ct = 0, max_len = 0;
    unordered_map<int, int> MEM;

    for (int i = 0; i < s.length(); ++i)
    {
        ct += s[i] == '0' ? 1 : -1;

        if (ct > 0)
            max_len = max(max_len, i + 1);

        if (!MEM.count(ct))
            MEM[ct] = i;

        if (MEM.count(ct - 1))
            max_len = max(max_len, i - MEM[ct - 1]);
    }

    return max_len;
}

int main()
{
    int n = 0;
    string s;

    cin >> n;
    cin >> s;

    cout << getMaxLen(s);

    return 0;
}