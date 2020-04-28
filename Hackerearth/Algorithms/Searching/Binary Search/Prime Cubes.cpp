#include <bits/stdc++.h>

using namespace std;

#define ull long long int

#define SIEVE_SIZE 1000001
bool sieve[SIEVE_SIZE];
vector<int> primes;

void generateSieve()
{
    for (int i = 0; i < SIEVE_SIZE; ++i)
    {
        sieve[i] = true;
    }
    sieve[0] = sieve[1] = false;

    for (int i = 2; i * i <= SIEVE_SIZE; ++i)
    {
        for (int j = i * i; j < SIEVE_SIZE; j += i)
        {
            sieve[j] = false;
        }
    }

    for (int i = 0; i < SIEVE_SIZE; ++i)
        if (sieve[i])
            primes.push_back(i);
}

int main()
{
    generateSieve();
    ull n = 0, val = 0;
    cin >> n;

    for (int &c : primes)
    {
        val = n - 9 - powl(c, 3);

        if (powl((ull)(cbrtl(val)), 3) != val)
            continue;

        val = cbrtl(val);
        if (sieve[val])
        {
            cout << "1 2 " << c << " " << val;
            return 0;
        }
    }

    cout << "-1";

    return 0;
}