#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

int main()
{
    ll N;
    cin >> N;
    cin.ignore();
    ll C;
    cin >> C;
    cin.ignore();

    vector<ll> B(N, 0);
    ll sum = 0;

    for (size_t i = 0; i < N; i++)
    {
        cin >> B[i];
        cin.ignore();
        sum += B[i];
    }

    if (sum < C)
    {
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }

    sort(B.begin(), B.end());
    ll cur_rat = C / N;
    ll tmp = 0, d = 0;

    for (size_t i = 0; i < N; ++i)
    {
        if (i + 1 == N)
            tmp = C;
        else
            tmp = min(B[i], cur_rat);
        cout << tmp << "\n";
        C -= tmp;
        d = N - i - 1;
        if (d)
            cur_rat = C / d;
    }
}