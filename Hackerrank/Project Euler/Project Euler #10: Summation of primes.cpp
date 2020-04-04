#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define ll long long int
#define SIEVE_SIZE 2000000

ll primeSumSieve[SIEVE_SIZE];

void generateSieve()
{
    /*
        generates the sieve
        also,
        stores the sum of primes upton n in primeSumSieve[n]
        (for better efficiency in multiple testcases)
    */
    for (int i = 0; i < SIEVE_SIZE; ++i)
        primeSumSieve[i] = 1;

    primeSumSieve[0] = primeSumSieve[1] = 0;

    for (size_t i = 2; i * i <= SIEVE_SIZE; ++i)
    {
        if (primeSumSieve[i])
        {
            for (size_t j = i * i; j <= SIEVE_SIZE; j += i)
                primeSumSieve[j] = 0;
        }
    }

    ll p_sum = 0;
    for (size_t i = 2; i <= SIEVE_SIZE; ++i)
    {
        if (primeSumSieve[i])
            p_sum += i;
        primeSumSieve[i] = p_sum;
    }
}

int main()
{
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int t = 0, n = 0;
    cin >> t;

    generateSieve();

    while (t--)
    {
        cin >> n;
        cout << primeSumSieve[n] << "\n";
    }

    return 0;
}
