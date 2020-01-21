#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

int main()
{
    int n;
    int max_so_far = -999999;
    int max_diff = 0;

    cin >> n;
    cin.ignore();
    for (int i = 0; i < n; i++)
    {
        int v;
        cin >> v;
        cin.ignore();
        if (v > max_so_far)
        {
            max_so_far = v;
        }
        else
        {
            max_diff = max(max_diff, max_so_far - v);
        }
    }

    cout << max_diff * -1 << "\n";
}