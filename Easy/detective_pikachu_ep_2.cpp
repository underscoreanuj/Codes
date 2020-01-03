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
 
string *grid;
int init_x, init_y;
int width;
int height;

bool isValidDir(int x, int y) {
    if(x < 0 || y < 0 || x >= height || y >= width) return false;
    
    return true;
}

int getDir(char dir) {
    if(dir == '^') return 0;
    if(dir == '>') return 1;
    if(dir == 'v') return 2;
    if(dir == '<') return 3;
}

void moveAlong(int &x, int &y, char &dir, string side) {
    vector<pair<int, int> > DIRS = {{-1,0}, {0,1}, {1,0}, {0,-1}};
    vector<char> DIRS_C = {'^', '>', 'v', '<'};
    int ind = getDir(dir);
    int t_x = 0, t_y = 0;
    
    int inc_first = 1, inc_after = 3;
    
    if(side == "L") {
        inc_first = 3;
        inc_after = 1;
    }
    
    ind = (ind+inc_first)%4;
        
    for(int i=0; i<4; ++i) {
        t_x = x + DIRS[ind].first;
        t_y = y + DIRS[ind].second;

        if(isValidDir(t_x, t_y) && grid[t_x][t_y] != '#') {
            x = t_x;
            y = t_y;
            dir = DIRS_C[ind];

            return;
        }
        ind = (ind+inc_after)%4;
    }
    
    grid[x][y] = '0';
}

int main()
{
    cin >> width >> height; cin.ignore();
    
    
    grid = new string[height];
    
    int x = 0, y = 0;
    init_x = init_y = 0;
    
    char dir;
    
    for (int i = 0; i < height; i++) {
        cin >> grid[i]; cin.ignore();
        
        int pos_right = grid[i].find(">");
        int pos_left = grid[i].find("<");
        int pos_up = grid[i].find("^");
        int pos_down = grid[i].find("v");
        
        
        if(pos_right != string::npos) {
            dir = '>';
            x = i;
            y = pos_right;
        }
        else if(pos_left != string::npos) {
            dir = '<';
            x = i;
            y = pos_left;
        }
        else if(pos_up != string::npos) {
            dir = '^';
            x = i;
            y = pos_up;
        }
        else if(pos_down != string::npos) {
            dir = 'v';
            x = i;
            y = pos_down;
        }
    }
    
    init_x = x;
    init_y = y;
    
    string side;
    cin >> side; cin.ignore();
    
    
    grid[x][y] = '1';
    moveAlong(x, y, dir, side);
    ++grid[x][y];
    
    
    while(!(x == init_x && y == init_y)) {
        moveAlong(x, y, dir, side);
        ++grid[x][y];
    }
    
    --grid[init_x][init_y];
    
    for (int i = 0; i < height; i++) {
        cout << grid[i] << endl;
    }
}