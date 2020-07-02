#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 * 
 * 
 * while(x) {
            cerr<<"\n ---------- "<<i<<" ::    "<<x<<"    -> "<<ct<<" : "<<prev_ct<<"\n";
            int rem = x%10;
            int m = rem%i;
            ++ct;
            while(x && rem%i == m) {
                x /= 10;
                rem = x%10;
            }
        }
 * 
 **/

int getInt(char c)
{
    if (c >= '0' && c <= '9')
        return c - '0';
    return 0;
}

int getClump(string N)
{

    int ct = 0, prev_ct = 1, len = N.length();

    for (int i = 2; i <= 9; ++i)
    {
        ct = 0;

        for (int j = 0; j < len; ++j)
        {
            ++ct;
            int m = getInt(N[j]) % i;
            while (j < len && getInt(N[j]) % i == m)
            {
                ++j;
            }
            --j;
        }

        if (prev_ct > ct)
            return i;

        prev_ct = ct;
    }

    return -1;
}

int main()
{
    string N;
    getline(cin, N);

    int res = getClump(N);
    if (res == -1)
        cout << "Normal\n";
    else
        cout << res << "\n";
}