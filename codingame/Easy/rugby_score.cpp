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

    int try_limit = N/5;
    int trans_limit = try_limit;
    int pen_limit = N/3;
    
    for(int t=0; t<=try_limit; ++t) {
        for(int ts=0; ts<=t; ++ts) {
            for(int p=0; p<=pen_limit; ++p) {
                if(t*5+ts*2+p*3 == N) {
                    cout<<t<<" "<<ts<<" "<<p<<"\n";
                }
            }
        }
    }   
    
}