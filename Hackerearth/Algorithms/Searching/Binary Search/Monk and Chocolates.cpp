#include <bits/stdc++.h>

using namespace std;

int maxValidLength(string &s, int k, char ch)
{
    int l = 0, r = 0, max_res = 0, ct = 0;

    while (r < s.length())
    {
        if (s[r] != ch)
            ++ct;

        while (ct > k)
        {
            if (s[l] != ch)
                --ct;
            ++l;
        }

        max_res = max(max_res, r - l + 1);

        ++r;
    }

    return max_res;
}

int main()
{
    int t = 0, n = 0, m = 0;
    string s;
    cin >> t;

    while (t--)
    {
        cin >> n >> m;
        cin >> s;
        int ct = 0, max_res = 0;

        for (char c = 'a'; c <= 'z'; ++c)
            max_res = max(max_res, maxValidLength(s, m, c));
        for (char c = 'A'; c <= 'Z'; ++c)
            max_res = max(max_res, maxValidLength(s, m, c));

        cout << max_res << "\n";
    }

    return 0;
}