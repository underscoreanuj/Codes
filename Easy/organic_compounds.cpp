#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

bool isValidIdx(int i, int j, int N, int len) {
    if(i<0 || j<0 || i>= N || j>= len) return false;
    
    return true;
}


bool isDigit(char c) {
    return (c >= '0' && c <= '9');
}


int main()
{
    int N;
    cin >> N; cin.ignore();
    
    vector<string> comp;
    vector<pair<int, int>> dirs = {{-1, 0}, {0, 3}, {1, 0}, {0, -3}};
    
    for (int i = 0; i < N; i++) {
        string COMPOUND;
        getline(cin, COMPOUND);
        comp.push_back(COMPOUND);
    }
    
    int len = 0, h_c = 0, b_c = 0, x = -1, y = -1;
    
    for(int i=0; i<N; ++i) {
        len = comp[i].length();
        for(int j=0; j<len; ++j) {
            if(comp[i][j] == 'H') {
                h_c = b_c = 0;
                h_c = comp[i][j+1] - '0';
                
                for(auto d : dirs) {
                    x = i + d.first;
                    y = j + d.second;
                    
                    if(isValidIdx(x, y, N, len) && isDigit(comp[x][y])) {
                        b_c += comp[x][y] - '0';
                    }
                    
                }
                
                if(h_c + b_c != 4) {
                    cout<<"INVALID\n";
                    return 0;
                }
                
            }
        }
    }
    
    cout<<"VALID\n";
    return 0;
    

}