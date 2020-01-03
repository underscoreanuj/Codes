#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

bool isValidDir(int i, int j, int h, int w) {
    if(i < 0 || j < 0 || i >= h || j >= w) return false;
    
    return true;
}

int main()
{
    int width;
    int height;
    cin >> width >> height; cin.ignore();
    
    vector<pair<int, int> > dirs = {{1,0}, {0,1}, {-1,0}, {0,-1}};
    string *grid = new string[height];
    
    for (int i = 0; i < height; i++) {
        cin >> grid[i]; cin.ignore();
    }
    
    int ct = 0, x = 0, y = 0;
    
    for(int i=0; i<height; ++i) {
        for(int j=0; j<width; ++j) {
            if(grid[i][j] == '0') {
                ct = 0;
                for(auto d : dirs) {
                    x = i + d.first;
                    y = j + d.second;
                    
                    if(isValidDir(x, y, height, width) && grid[x][y] != '#') ++ct;
                }
                grid[i][j] = ct + '0';
            }
        }
    }
    
    for (int i = 0; i < height; i++) {
        cout << grid[i] << endl;
    }
}