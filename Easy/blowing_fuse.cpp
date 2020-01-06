#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

int main()
{
    int n;
    int m;
    int c;
    
    int sum = 0, max_sum = -999999;
    vector<int> devices;
    
    cin >> n >> m >> c; cin.ignore();
    
    for (int i = 0; i < n; i++) {
        int nx;
        cin >> nx; cin.ignore();
        
        devices.push_back(nx);
    }
    
    for (int i = 0; i < m; i++) {
        int mx;
        cin >> mx; cin.ignore();
        
        if(devices[mx-1] > c) {
            cout<<"Fuse was blown.\n";
            return 0;
        }
        
        if(devices[mx-1] > 0) { // switch on
            sum += devices[mx-1];
            
            if(sum > c) {
                cout<<"Fuse was blown.\n";
                return 0;
            }
            
            if(max_sum < sum) max_sum = sum;
            
            devices[mx-1] *= -1;
        }
        else if(devices[mx-1] < 0) { // switch off
            devices[mx-1] *= -1;
            sum -= devices[mx-1];
        }
        
    }

    cout<<"Fuse was not blown.\nMaximal consumed current was "<<max_sum<<" A.\n";
}