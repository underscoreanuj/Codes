#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t = 0, k = 0, ct = 0;
    string s;

    cin >> t;

    while (t--)
    {
        cin >> k;
        cin >> s;

        vector<int> preSum(s.length() + 1, 0);
        ct = 0;

        for (int i = 0; i < s.length(); ++i)
            preSum[i + 1] = preSum[i] + (s[i] - 'a' + 1);

        for (int i = 0; i < preSum.size(); ++i)
        {
            if (binary_search(preSum.begin(), preSum.end(), preSum[i] + k))
                ++ct;
        }

        cout << ct << "\n";
    }

    return 0;
}