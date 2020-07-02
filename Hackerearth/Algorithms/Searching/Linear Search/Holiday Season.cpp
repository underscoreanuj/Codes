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
    long long int n = 0, count = 0, ct = 0;
    cin >> n;

    string s;
    cin >> s;

    if (s.length() < 4)
    {
        cout << "0";
        return 0;
    }

    unordered_map<char, long long> MEM1;
    unordered_map<char, long long> MEM2;

    for (int i = 0; i < n; ++i)
    {
        if (MEM1.count(s[i]))
        {
            if (MEM2.count(s[i]))
            {
                count += MEM2[s[i]];
            }
            ct = 1;
            for (int j = MEM1[s[i]] + 1; j < i; ++j)
            {
                if (MEM2.count(s[j]))
                    MEM2[s[j]] += ct;
                else
                    MEM2[s[j]] = ct;

                if (s[j] == s[i])
                    ++ct;
            }
        }
        else
        {
            MEM1[s[i]] = i;
        }
    }

    cout << count;

    return 0;
}

Language : C++ 14
