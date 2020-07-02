#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n = 0, count = 0;
    long long int w = 0, h = 0, ratio1 = 0, ratio2 = 0;
    cin >> n;

    while (n--)
    {
        cin >> w >> h;
        if (w < h)
            swap(w, h);

        if ((16 * h) <= (10 * w) && (17 * h) >= (10 * w))
            ++count;
    }

    cout << count;

    return 0;
}