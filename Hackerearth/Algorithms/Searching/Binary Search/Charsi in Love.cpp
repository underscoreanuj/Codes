#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n = 0;
    cin >> n;
    int sum = 1, cur = 2;
    unordered_set<int> MEM;
    MEM.insert(sum);

    while (sum < n)
    {
        if (MEM.count(n - sum))
        {
            cout << "YES";
            return 0;
        }
        sum += cur;
        ++cur;
        MEM.insert(sum);
    }

    cout << "NO";

    return 0;
}