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
    string b;
    getline(cin, b);
    
    int prev_zero = 0, prev_prev_zero = -1, max_so_far = -999999;
    
    for(int i=0; i<b.length(); ++i) {
        if(b[i] == '0') {
            prev_zero = i;
            break;
        }
    }
    
    int i = 0;
    
    for(i=prev_zero+1; i<b.length(); ++i) {
        if(b[i] == '0') {
            max_so_far = max(max_so_far, ((i - prev_zero - 1) + (prev_zero - prev_prev_zero)));
            prev_prev_zero = prev_zero;
            prev_zero = i;
        }
    }
    
    max_so_far = max(max_so_far, ((i - prev_zero - 1) + (prev_zero - prev_prev_zero)));
    
    cout<<max_so_far<<"\n";
    
}