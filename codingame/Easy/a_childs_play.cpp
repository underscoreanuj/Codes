#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/


class Move{
public:
    int x;
    int y;
    int dir;
    
    Move(int x, int y, int dir) {
        this->x = x;
        this->y = y;
        this->dir = dir;
    }
    
    bool operator==(const Move& obj) const {
        return (this->x == obj.x && this->y == obj.y && this->dir == obj.dir);
    }
    
};

class MyHash{
public:
    size_t operator()(const Move& obj) const {
        return (hash<int>()(obj.x) ^ hash<int>()(obj.y) ^ hash<int>()(obj.dir));
    }
};


int main()
{
    int w;
    int h;
    cin >> w >> h; cin.ignore();
    long long n;
    cin >> n; cin.ignore();
    
    string *grid = new string[h];
    int x = 0, y = 0;
    bool found = false;
    
    for (int i = 0; i < h; i++) {
        getline(cin, grid[i]);
        
        if(!found) {
            y = grid[i].find("O");
            if(y != string::npos) {
                x = i;
                found = true;
            }
        }
    }
    
    int t_x = x, t_y = y;
    int idx = 0;
    int DIR_X[4] = {-1, 0, 1, 0};
    int DIR_Y[4] = {0, 1, 0, -1};
    
    unordered_set<Move, MyHash> moves;
    vector<Move> move_list;
    
    while(true) {
        while(grid[t_x+DIR_X[idx]][t_y+DIR_Y[idx]] == '#') idx = (idx+1)%4;
        
        t_x += DIR_X[idx];
        t_y += DIR_Y[idx];
        
        Move obj(t_x, t_y, idx);
        
        if(moves.find(obj) != moves.end()) break;
        
        moves.insert(obj);
        move_list.push_back(obj);
    }
    
    n = n%move_list.size();
    
    cout<<move_list[n-1].y<<" "<<move_list[n-1].x;
    
}