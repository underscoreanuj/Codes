#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <complex>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

int main()
{
    double x, y;
    cin >> x >> y;
    cin.ignore();
    int m;
    cin >> m;
    cin.ignore();

    complex<double> c(x, y);
    complex<double> f(0, 0);

    int limit = 1;

    while (limit < m)
    {
        f = f * f + c;
        if (abs(f) > 2)
            break;
        ++limit;
    }

    cout << min(limit, m) << "\n";
}