#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool sieve[1000000];

void generateSieve()
{
    for (int i = 0; i < 1000000; ++i)
        sieve[i] = true;

    sieve[0] = sieve[1] = false;
    for (int i = 2; i * i <= 1000000; ++i)
    {
        if (sieve[i])
        {
            for (int j = i * i; j <= 1000000; j += i)
                sieve[j] = false;
        }
    }
}

vector<int> getPrimes()
{
    generateSieve();

    vector<int> res;
    for (int i = 0; i < 1000000; ++i)
    {
        if (sieve[i])
            res.push_back(i);
    }

    return res;
}

int main()
{
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    vector<int> primes = getPrimes();
    int t = 0, n = 0;
    cin >> t;

    while (t--)
    {
        cin >> n;
        cout << primes[n - 1] << "\n";
    }

    return 0;
}
