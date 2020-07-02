#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define ll long long int
ll MEM[1000000];

ll getCountOfDivisors(int n)
{
    if (MEM[n] > 0)
        return MEM[n];

    ll init_n = n;
    ll ct = 0;

    while (n % 2 == 0)
    {
        ++ct;
        n >>= 1;
    }

    ll result = ct == 0 ? 1 : ct + 1;

    for (int i = 3; i * i <= n; ++i)
    {
        if (n % i == 0)
        {
            ct = 0;
            while (n % i == 0)
            {
                ++ct;
                n /= i;
            }
            result *= (ct + 1);
        }
    }

    if (n > 2)
        result *= 2;

    MEM[init_n] = result;

    return result;
}

// *********************** initial approach (accepted) ***********************

// ll getFirstTriangularNumber(ll n) {
//     ll val = 1, ct = 2;
//     while(true) {
//         // cout<<"\n"<<val<<" :: "<<getCountOfDivisors(val)<<"\n";
//         if(getCountOfDivisors(val) > n) {
//             return val;
//         }
//         val += ct;
//         ++ct;
//     }
// }

// *********************** optimal approach ***********************

ll getFirstTriangularNumberOptimal(ll n)
{
    /*
    refers this: https://projecteuler.net/overview=012
    
        sum upto n numbers = n*(n+1)/2
        number of divisors = num_divisors(n) * num_divisors((n+1)/2)  (if n is odd)
        number of divisors = num_divisors(n/2) * num_divisors(n+1)  (if n is even)
        we can also memoize the values that have already been conputed
        in calculating the number of divisors
    */
    ll val = 1, dvCt = 0;

    while (true)
    {
        if (~val & 1)
        { // val is even
            dvCt = getCountOfDivisors(val / 2) * getCountOfDivisors((val + 1));
        }
        else
        { // val is odd
            dvCt = getCountOfDivisors(val) * getCountOfDivisors((val + 1) / 2);
        }

        if (dvCt > n)
        {
            return (val * (val + 1)) / 2;
        }

        ++val;
    }

    return -1;
}

int main()
{
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    ll t = 0, n = 0;
    cin >> t;

    for (int i = 0; i < 1000000; ++i)
        MEM[i] = -1;

    while (t--)
    {
        cin >> n;
        // cout<<getFirstTriangularNumber(n)<<"\n";
        cout << getFirstTriangularNumberOptimal(n) << "\n";
    }

    return 0;
}
