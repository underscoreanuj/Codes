#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

int main()
{
    int w;
    int h;
    int countX;
    int countY;
    cin >> w >> h >> countX >> countY; cin.ignore();
    
    int ct = 0;
    unordered_map<int, int> M;
    
    int *X = new int[countX+2];
    int *Y = new int[countY+2];
    
    X[0] = Y[0] = 0;
    X[countX+1] = w;
    Y[countY+1] = h;
    
    for (int i = 0; i < countX; i++) {
        cin >> X[i+1]; cin.ignore();
    }
    for (int i = 0; i < countY; i++) {
        cin >> Y[i+1]; cin.ignore();
    }

    for (int i = 0; i < countX+2; i++) {
        for(int j=i+1; j<countX+2; ++j) {
            ++M[abs(X[i] - X[j])];
        }
    }
    
    int tmp = 0;
    for (int i = 0; i < countY+2; i++) {    
        for(int j=i+1; j<countY+2; ++j) {
            tmp = abs(Y[i] - Y[j]);
            if(M.find(tmp) != M.end()) {
                ct += M[tmp];
            }
        }
    }

    cout << ct << endl;
}