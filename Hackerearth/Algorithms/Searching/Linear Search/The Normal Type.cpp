#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long int n = 0, count = 0, distinct_size = 0;
    cin >> n;
    vector<long long int> A(n, 0);
    unordered_map<long long int, long long int> D;

    for (int i = 0; i < n; ++i)
    {
        cin >> A[i];
        D.insert({A[i], 0});
    }

    distinct_size = D.size();
    D.clear();

    int i = 0, j = 0;

    for (int i = 0; i < n; ++i)
    {
        while (D.size() < distinct_size && j < n)
        {
            ++D[A[j++]];
        }

        if (D.size() == distinct_size)
        {
            count += n - j + 1;
        }

        --D[A[i]];
        if (D[A[i]] == 0)
            D.erase(A[i]);
    }

    cout << count;

    return 0;
}