#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <cmath>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/


bool liesWithinCircle(double radius, double x, double y) {
    return (x*x + y*y) <= (radius*radius);
}

bool liesWithinSquare(double side, double x, double y) {
    return (max(abs(x), abs(y)) <= side/2);
}

bool liesWithinDiamond(double side, double x, double y) {
    return (abs(x) + abs(y) <= side/2);
}

int getScore(double sq_size, double x, double y) {
    if(liesWithinDiamond(sq_size, x, y)) return 15;
    if(liesWithinCircle(sq_size/2, x, y)) return 10;
    if(liesWithinSquare(sq_size, x, y)) return 5;

    return 0;
}


class MySort{
public:
    bool operator()(const pair<string, int> o1, const pair<string, int> o2) {
        return o1.second > o2.second;
    }
};


int main()
{
    double SIZE;
    cin >> SIZE; cin.ignore();
    int N;
    cin >> N; cin.ignore();
    
    unordered_map<string, int> scores;
    vector<pair<string, int>> board;
    
    for (int i = 0; i < N; i++) {
        string name;
        getline(cin, name);
        scores.insert({name, 0});
        board.push_back({name, 0});
    }
    
    int T;
    cin >> T; cin.ignore();
    for (int i = 0; i < T; i++) {
        string throwName;
        double throwX;
        double throwY;
        cin >> throwName >> throwX >> throwY; cin.ignore();
        
        scores[throwName] += getScore(SIZE, throwX, throwY);
    }
    
    for(int i=0; i<N; ++i) {
        board[i].second = scores[board[i].first];
    }
    
    stable_sort(board.begin(), board.end(), MySort());
    
    for(auto c : board) cout<<c.first<<" "<<c.second<<"\n";
    
}