#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define ll long long int

ll gcd(ll a, ll b)
{
    // returns the gcd of two numbers
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

ll lcm(ll a, ll b)
{
    // returns the lcm of two numbers, lcm(x,y) = (x*y)/gcd(x,y)
    return (a * b) / gcd(a, b);
}

ll getSmallestMultiple(ll n)
{
    // returns the smallest multiple divisible by all numbers in [1, n]
    // lcm(x,y,z)  lcm(lcm(x,y),z)

    ll result = 1;

    for (int i = 2; i <= n; ++i)
        result = lcm(result, i);

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
        cout << getSmallestMultiple(n) << "\n";
    }

    return 0;
}
