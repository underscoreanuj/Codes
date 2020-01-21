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
    int L;
    cin >> L; cin.ignore();
    int H;
    cin >> H; cin.ignore();
    string T;
    getline(cin, T);
    
    for(int i=0; i<T.length(); ++i) {
        if('a' <= T[i] && T[i] <= 'z' ) {
            T[i] = T[i] - 32;
            cerr<<"\n-*-";
        }
        else if(T[i] < 'A' || T[i] > 'Z') {
            T[i] = char(91);   
        }
    }
    
    int idx = 0;
    
    for (int i = 0; i < H; i++) {
        string ROW;
        getline(cin, ROW);
        for(int j=0; j<T.length(); ++j) {
            idx = L*(T[j]-65);
            cout<< ROW.substr(idx, L);
        }
        cout<<endl;
    }

    // cout << "answer" << endl;
}