#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/


bool isValidDir(int x, int y, int size) {
    if(x < 0 || x >= size || y < 0 || y >= size) return false;
    
    return true;
}

void spreadLight(char **grid, int i, int j, int l, int size, int flag) {
    
    if(l <= 0) return;
    
    vector<pair<int, int> > dirs = {{-1,-1}, {1,1}, {-1,1}, {1,-1}, {0,-1}, {0,1}, {1,0}, {-1,0}};
    
    if(grid[i][j] == 'C' && flag) grid[i][j] = l + '0';
    if(grid[i][j] == 'X') grid[i][j] = '0';
    
    grid[i][j] = char(max(int(grid[i][j]), int(l + '0')));
    
    for(auto d : dirs) {
        int x = i + d.first;
        int y = j + d.second;
        
        if(isValidDir(x, y, size)) spreadLight(grid, x, y, l-1, size, 0);
    }
    
}

int main()
{
    
    int N;
    cin >> N; cin.ignore();
    int L;
    cin >> L; cin.ignore();
    
    char **grid = new char*[N];
    
    
    for (int i = 0; i < N; i++) {
        grid[i] = new char[N];
        for (int j = 0; j < N; j++) {
            cin>>grid[i][j];
        }
    }
    
    
    for(int i = 0; i < N; i++) {
        for(int j=0; j<N; ++j) {
            if(grid[i][j] == 'C') {
                spreadLight(grid, i, j, L, N, 1);
            }
            else if(grid[i][j] == 'X') {
                grid[i][j] = '0';
            }
        }
    }
    
    int ct = 0;
    
    for(int i = 0; i < N; i++)
        for(int j=0; j<N; ++j)
            if(grid[i][j] == '0') ++ct;

    cout << ct << endl;
}