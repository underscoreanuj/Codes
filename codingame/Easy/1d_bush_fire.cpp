#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/


int getDropCount(string s) {
    int ct = 0;
    int n = s.length();
    int i = 0;
    
    while(i<n) {
        if(s[i] == 'f') {
            ++ct;
            i += 2;
        }
        ++i;
    }
    
    return ct;
}


int main()
{
    int N;
    cin >> N; cin.ignore();
    for (int i = 0; i < N; i++) {
        string line;
        getline(cin, line);
        
        cout<<getDropCount(line)<<"\n";
        
    }
}