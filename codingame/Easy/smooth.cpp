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
    int N;
    cin >> N; cin.ignore();
    
    bool flag = false;
    
    for (int i = 0; i < N; i++) {
        long long F;
        cin >> F; cin.ignore();
        
        flag = false;
        while(F) {
            
            if(F == 1) {
                flag = true;
                break;
            }
            
            if(F%2 == 0) F /= 2;
            else if(F%3 == 0) F /= 3;
            else if(F%5 == 0) F /= 5;
            else break;
        }
        
        if(flag) cout<<"VICTORY\n";
        else cout<<"DEFEAT\n";
        
    }

}