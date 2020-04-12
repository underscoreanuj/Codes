#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define ll long long int
#define MEM_SIZE 5000001
#define CACHE_SIZE 5000001

int MEM[MEM_SIZE];
int CACHE[CACHE_SIZE];

int getCollatzSeq(ll n)
{
    // returns the length of the collatz sequence of n
    // uses recursion and memoization to improve performance
    if (n < 0)
        return 0;
    if (n == 1)
        return 1;

    if (n < MEM_SIZE && MEM[n] > 0)
        return MEM[n];

    int res = 1;

    if (~n & 1)
        res += getCollatzSeq(n >> 1);
    else
        res += getCollatzSeq(3 * n + 1);

    if (n < MEM_SIZE)
        MEM[n] = res;

    return res;
}

void preComputeSeq()
{
    // precomputes the collatz sequences for all n in given range 5*10^6
    // and caches the the result for each number beforehand
    for (int i = 0; i < MEM_SIZE; ++i)
        MEM[i] = -1;

    int seq = 0, max_seq = -1, max_idx = -1;
    for (int i = 1; i < CACHE_SIZE; ++i)
    {
        seq = getCollatzSeq(i);
        if (seq >= max_seq)
        {
            max_seq = seq;
            max_idx = i;
        }
        CACHE[i] = max_idx;
    }
}

int main()
{
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    preComputeSeq();

    int t = 0, n = 0;
    cin >> t;
    while (t--)
    {
        cin >> n;
        cout << CACHE[n] << "\n";
    }

    return 0;
}
