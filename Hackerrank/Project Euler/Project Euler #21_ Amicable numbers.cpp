#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

vector<int> sieve;
vector<int> preSum;

void generateSieve()
{
    sieve = vector<int>(1000001, 1);
    preSum = vector<int>(100001, 0);
    sieve[1] = 0;
    preSum[0] = 0;

    for (int i = 2; i < sieve.size(); ++i)
    {
        for (int j = i + i; j < sieve.size(); j += i)
        {
            sieve[j] += i;
        }
    }

    for (int i = 2; i < 100001; ++i)
    {
        if (sieve[i] != i && sieve[sieve[i]] == i)
        {
            preSum[i] += i;
        }
        preSum[i] += preSum[i - 1];
    }
}

int getAmicableNumbersSum(int n)
{
    return preSum[n];
}

int main()
{
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    generateSieve();

    int t = 0, n = 0;
    cin >> t;

    while (t--)
    {
        cin >> n;
        cout << getAmicableNumbersSum(n) << "\n";
    }

    return 0;
}
