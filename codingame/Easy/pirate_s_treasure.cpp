#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
 
int W, H;

bool isValid(int i, int j)  {
    if(i < 0 || j < 0 || i>=H || j >=W) return false;
    
    return true;
}


int main()
{
    
    cin >> W; cin.ignore();
    cin >> H; cin.ignore();
    
    vector<vector<int> > grid(H);
    vector<pair<int, int> > dirs = {{-1,-1}, {-1,0}, {-1,1}, {0,1}, {1,1}, {1,0}, {1,-1}, {0,-1}};
    
    for (int i = 0; i < H; i++) {
        grid[i] = vector<int>(W);
        for (int j = 0; j < W; j++) {
            cin >> grid[i][j]; cin.ignore();
        }
    }
    
    
    for(auto r : grid) {
        for(auto e : r) {
            cerr<<e<<" ";
        }
        cerr<<"\n";
    }
    
    
    int x=0, y=0;
    bool flag = true;
    
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if(grid[i][j] == 0) {
                flag = true;
            
                for(auto d:dirs) {
                    x = i + d.first;
                    y = j + d.second;
                    if(isValid(x, y) && grid[x][y] != 1) {
                        flag = false;
                        break;
                    }
                }
                
                if(flag) {
                    cout<<j<<" "<<i<<"\n";
                    return 0;
                }
            }
        }
    }
    
}