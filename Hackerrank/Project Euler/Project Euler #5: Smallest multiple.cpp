#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define ll long long int

// ll gcd(ll a, ll b) {
//     // returns the gcd of two numbers
//     if(b == 0) return a;
//     return gcd(b, a%b);
// }

// ll lcm(ll a, ll b) {
//     // returns the lcm of two numbers, lcm(x,y) = (x*y)/gcd(x,y)
//     return (a*b)/gcd(a, b);
// }

// ll getSmallestMultiple(ll n) {
//     // returns the smallest multiple divisible by all numbers in [1, n]
//     // lcm(x,y,z)  lcm(lcm(x,y),z)

//     ll result = 1;

//     for(int i=2; i<=n; ++i)
//         result = lcm(result, i);

//     return result;
// }

bool seive[50];

void generateSeive()
{
    for (int i = 0; i < 50; ++i)
        seive[i] = true;

    seive[0] = seive[1] = false;
    for (int i = 2; i * i < 50; ++i)
    {
        if (seive[i])
        {
            for (int j = i * i; j < 50; j += i)
            {
                seive[j] = false;
            }
        }
    }
}

ll getSmallestMultipleOptimal(ll n)
{
    /*
        refer this : https://projecteuler.net/overview=005
        we need all prime numbers upto n (n <= 40, given)
    */

    ll result = 1;

    vector<int> primes;
    for (int i = 2; i <= n; ++i)
    {
        if (seive[i])
            primes.push_back(i);
    }

    bool flag = true;

    for (int i = 0; i < primes.size(); ++i)
    {
        if (primes[i] * primes[i] > n)
            flag = false;
        if (flag)
        {
            result *= pow(primes[i], floor(log(n) / log(primes[i])));
        }
        else
        {
            result *= primes[i];
        }
    }

    return result;
}

int main()
{
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    ll t = 0, n = 0;
    cin >> t;

    generateSeive();

    while (t--)
    {
        cin >> n;
        cout << getSmallestMultipleOptimal(n) << "\n";
    }

    return 0;
}
