#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define ll long long int

ll getLargestPrimeFactor(ll n)
{
    ll largest_prime_factor = 2;

    // divide by two (prime factor) untill n becomes odd;
    while (n % 2 == 0)
        n >>= 1;

    // 2 is the only prime factor
    if (n == 1)
        return 2;

    // skip even numbers
    for (size_t i = 3; i * i <= n; i += 2)
    {
        if (n % i == 0)
        {
            largest_prime_factor = i;
            while (n % i == 0)
                n = n / i;
        }
    }

    // n itself is a prime now
    if (n > 2)
        return n;

    return largest_prime_factor;
}

int main()
{
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    ll t = 0, n = 0;
    cin >> t;

    while (t--)
    {
        cin >> n;
        cout << getLargestPrimeFactor(n) << "\n";
    }

    return 0;
}
