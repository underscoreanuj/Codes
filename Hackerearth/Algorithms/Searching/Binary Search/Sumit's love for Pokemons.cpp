#include <bits/stdc++.h>

using namespace std;

int maxVaidLength(string &s, int &k, char &ch)
{
    int ct = 0, max_res = 0, l = 0;

    for (int r = 0; r < s.length(); ++r)
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
    }

    return max_res;
}

int main()
{
    int t = 0, n = 0, k = 0;
    string s;
    cin >> t;

    while (t--)
    {
        cin >> n >> k;
        cin >> s;
        int max_res = 0;

        for (char c = 'a'; c <= 'z'; ++c)
            max_res = max(max_res, maxVaidLength(s, k, c));
        for (char c = 'A'; c <= 'Z'; ++c)
            max_res = max(max_res, maxVaidLength(s, k, c));

        cout << max_res << "\n";
    }

    return 0;
}