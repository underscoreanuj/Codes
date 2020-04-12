#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define ll long long int

bool isPalindrome(ll n)
{
    if (n < 0 || (n % 10 == 0 && n != 0))
        return false;

    ll x = n;
    ll y = 0;
    while (y < x)
    {
        y = y * 10 + x % 10;
        x /= 10;
    }
    return x == y || x == y / 10;
}

ll getLargestPalinProduct(ll n)
{
    /*
        a 6-digit palindrome can be represented as: 
                       10^5*(a) + 10^4*(b) + 10^3*(c) + 10^2*(c) + 10^1*(b) + 10^0*(a)
        simplified as: 100001*(a) + 10010*(b) + 1100*(c)
        taking out 11: 11*(991*(a) + 910*(b) + 100*(c))
        this number must be equal to the product of two 3-digit numbers
    *** Hence, one of the numbers must be divisible by 11               (optimization)
    *** the fact that the product must not exceed the given value       (optimization)
    *** if at any point the product for a current j for i goes below    (optimization)
        the current maximum, we can stop looking further down the value
        of j for the given i
            
    */

    int result = 0;
    int step = 1;
    int start = 999;

    for (int i = 999; i >= 100; --i)
    {
        // atleast one of the numbers must be divisible by 11
        if (i % 11)
        {
            step = 11;
            start = min((ll)990, (n / i) - ((n / i) % 11));
        }
        else
        {
            step = 1;
            start = min((ll)999, n / i);
        }
        for (int j = start; j >= 100; j -= step)
        {
            int product = i * j;
            if (product < result)
                break;
            if (product < n && product < 1000000 && isPalindrome(product))
            {
                result = max(result, product);
            }
        }
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
        cout << getLargestPalinProduct(n) << "\n";
    }

    return 0;
}
