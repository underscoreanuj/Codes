#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define ll long long int

ll sumOfEvenFibonacciUpto(ll n)
{
    //finds and returns the sum of all even fibonacci numbers upto n
    ll result = 0;
    ll f = 1, s = 1;
    while (s <= n)
    {
        if (~s & 1)
            result += s;
        s = f + s;
        f = s - f;
    }

    return result;
}

int main()
{
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    ll t = 0, n = 0;
    cin >> t;

    while (t--)
    {
        cin >> n;
        cout << sumOfEvenFibonacciUpto(n) << "\n";
    }

    return 0;
}
