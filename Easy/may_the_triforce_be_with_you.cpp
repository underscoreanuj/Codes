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

    cout<<".";
    
    int spaces = 2*N-1, stars1=1, stars2=1;
    int omit = spaces;
    
    for(int i=0; i<2*N; ++i) {
        if(i < N) {
            for(int j=1; j<spaces; ++j) cout<<" ";
            for(int j=0; j<stars1; ++j) cout<<"*";
            
            stars1 += 2;
        }
        else {
            for(int j=1; j<spaces; ++j) cout<<" ";
            for(int j=0; j<stars2; ++j) cout<<"*";
            for(int j=0; j<omit; ++j) cout<<" ";
            for(int j=0; j<stars2; ++j) cout<<"*";
            
            omit -= 2;
            stars2 += 2;
        }
        
        if(i>0) --spaces;
        
        cout<<"\n";
    }

}