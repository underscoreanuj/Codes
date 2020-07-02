#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<int> getNumVecFromString(string s)
{
    // returns a vector of the given string of a very large number
    vector<int> res;
    for (char c : s)
        res.push_back(int(c - '0'));
    return res;
}

long long int getLargestProduct(string s, int k)
{
    // returns the larges product of a window of size k
    vector<int> num = getNumVecFromString(s);
    long long int max_res = 0, res = 1;
    int l = 0, r = k, n = num.size(); // using l and r for tracking the window
    bool flag = true, f = true;

    while (l + k < n && r < n)
    {
        if (flag)
        { // calculate window
            res = 1;
            f = true;
            for (int i = l; i < r; ++i)
            {
                if (num[i] == 0)
                { // 0 is found, calculate next window
                    f = false;
                    l = i + 1;
                    r = l + k;
                    break;
                }
                res *= num[i];
            }
            if (f)
            {
                max_res = max(max_res, res);
                flag = false;
            }
        }
        else
        { // slide window
            if (num[r] == 0)
            {
                flag = true;
                l = r + 1;
                r = l + k;
            }
            else
            {
                res /= num[l++];
                res *= num[r++];
                max_res = max(max_res, res);
            }
        }
    }

    return max_res;
}

int main()
{
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int t = 0, n = 0, k = 0;
    string num;
    cin >> t;

    while (t--)
    {
        cin >> n >> k;
        cin >> num;
        cout << getLargestProduct(num, k) << "\n";
    }

    return 0;
}
