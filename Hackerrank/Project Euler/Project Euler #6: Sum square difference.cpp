#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define ll long long int

ll getSumSquareDiff(ll n)
{
    // returns the difference between the square of sum of first n numbers [1,n]
    // and the sum of square of the first n numbers [1,n]
    // square of sum of first n numbers = (n*(n+1)/2)^2
    // sum of square of first n numbers = n*(n+1)*(2*n+1)/6
    // solve the difference to get the formula = n*(3*n^3 + 2*n^2 - 3*n - 2)/12
    return ((n * (3 * n * n * n + 2 * n * n - 3 * n - 2)) / 12);
}

int main()
{
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    ll t = 0, n = 0;
    cin >> t;

    while (t--)
    {
        cin >> n;
        cout << getSumSquareDiff(n) << "\n";
    }

    return 0;
}
