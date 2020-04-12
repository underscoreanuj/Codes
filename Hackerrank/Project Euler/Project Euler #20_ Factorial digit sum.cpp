#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <numeric>
using namespace std;

vector<int> multiplyVectors(vector<int> a, vector<int> b)
{
    vector<int> result(a.size() + b.size(), 0);

    for (int i = a.size() - 1; i >= 0; --i)
    {
        for (int j = b.size() - 1; j >= 0; --j)
        {
            result[i + j + 1] += a[i] * b[j];
            result[i + j] += result[i + j + 1] / 10;
            result[i + j + 1] %= 10;
        }
    }

    if (result[0] == 0)
        result.erase(result.begin());

    return result;
}

vector<int> getVector(int &n)
{
    vector<int> result;
    while (n)
    {
        result.push_back(n % 10);
        n /= 10;
    }
    reverse(result.begin(), result.end());

    return result;
}

vector<int> getFactorial(int n)
{
    if (n <= 1)
        return {1};
    return multiplyVectors(getVector(n), getFactorial(n - 1));
}

int getFactorialDigitSum(int &n)
{
    vector<int> fact = getFactorial(n);

    return accumulate(fact.begin(), fact.end(), 0);
}

int main()
{
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int t = 0, n = 0;
    cin >> t;

    while (t--)
    {
        cin >> n;
        cout << getFactorialDigitSum(n) << "\n";
    }

    return 0;
}
