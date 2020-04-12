#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

/*
        think an nxm lattice as an (n+1)x(m+1) grid,
        then we need to calculate the unique paths in that grid
        https://leetcode.com/problems/unique-paths/
        
        *** the O(1) formula can be repurposed here: calculate fact(n+m)/(fact(n)*fact(m))
*/

/*
def getLatticePaths(x, y):
    if x < y:
        return getLatticePaths(y, x)
    res = 1
    for i in range(x+1, x+y+1):
        res = res * i
        res = res // (i-x)

    return res % 1000000007


t = int(input())

while t:
    x, y = map(int, input().split())
    print(getLatticePaths(x, y))

    t = t-1;
*/

#define ll long long int
#define MOD 1000000007

vector<vector<ll>> tab;

void preCompute()
{
    tab = vector<vector<ll>>(501, vector<ll>(501, 0));

    for (int i = 0; i < 501; ++i)
    {
        for (int j = 0; j < 501; ++j)
        {
            if (i == 0 || j == 0)
            {
                tab[i][j] = 1;
            }
            else
            {
                tab[i][j] = (tab[i - 1][j] + tab[i][j - 1]) % MOD;
            }
        }
    }
}

int main()
{
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int t = 0, n = 0, m = 0;
    cin >> t;

    preCompute();

    while (t--)
    {
        cin >> n >> m;
        cout << tab[n][m] << "\n";
    }
    return 0;
}
