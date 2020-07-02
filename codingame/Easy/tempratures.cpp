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
    int n; // the number of temperatures to analyse
    cin >> n; cin.ignore();
    int min_temp = 5527;
    for (int i = 0; i < n; i++) {
        int t; // a temperature expressed as an integer ranging from -273 to 5526
        cin >> t; cin.ignore();
        if(abs(t) < abs(min_temp)) {
            min_temp = t;
        }
        else if(abs(t) == abs(min_temp)) {
            if(t > 0) min_temp = t;
        }
    }
    if(min_temp == 5527) min_temp = 0;

    cout << min_temp << endl;
}