#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int getLargestPythagoreanTriplet(int n)
{
    /*
        returns the larget pythagorean triplet whose sum is n

        a + b + c = n
        a^2 + b^2 = c^2

        a^2 + b^2 = (n-(a+b))^2
        solve it to get:
            b = (n^2 - 2*a*n)/(2*n - 2*a)
        also c = n - a - b
    */

    int a = 0, b = 0, c = 0;
    int res = -1;

    for (a = 1; a < n; ++a)
    {
        b = ((n * n - 2 * a * n) / (n - a)) / 2;
        if (b <= 0 || b <= a)
            continue;
        c = n - b - a;
        if (c <= b)
            continue;
        if (a * a + b * b == c * c) // if it is a pythagorean triplet
            res = max(res, a * b * c);
    }

    return res;
}

int main()
{
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int t = 0, n = 0;
    cin >> t;

    while (t--)
    {
        cin >> n;
        cout << getLargestPythagoreanTriplet(n) << "\n";
    }

    return 0;
}
