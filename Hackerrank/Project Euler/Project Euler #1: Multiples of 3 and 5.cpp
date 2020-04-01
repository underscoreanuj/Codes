#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define ll long long int

// returns sum of all numbers from 1-n that are multiples of 3 or 5
ll getSumofMultiples(ll n)
{
    --n; // numbers in [1,n), i.e. excluding n
    ll result = 0;

    ll by_three = n / 3; // count of numbers which are multiple of 3
    ll by_five = n / 5;  // count of numbers which are multiple of 5
    // numbers divisible by both must be divisible by their lcm -> lcm(3,5) = 5
    // these numbers should only be counted once
    ll by_fifteen = n / 15; // count of numbers which are multiple of 15

    // sum of AP = n/2(2*a+(n-1)*d)
    result = (by_three * (2 * 3 + (by_three - 1) * 3)) / 2;
    result += (by_five * (2 * 5 + (by_five - 1) * 5)) / 2;
    result -= (by_fifteen * (2 * 15 + (by_fifteen - 1) * 15)) / 2;

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
        cout << getSumofMultiples(n) << "\n";
    }

    return 0;
}
