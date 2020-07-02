#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

class Point{
public:    
    int x;
    int y;
    
    Point(int x, int y) {
        this->x = x;
        this->y = y;
    }
};


int getOrientation(Point a, Point b, Point c) {
    int ret = (b.x - a.x)*(c.y - b.y) - (c.x - b.x)*(b.y - a.y);
    if(ret == 0) return 0;
    return ret > 0 ? 1 : 2;
}


bool isInside(vector<Point> polygon, Point p) {
    
    int n = polygon.size();
    int next = 0, o = 0, flag = 0;
    
    for(int i=0; i<n; ++i) {
        next = (i+1)%n;
        
        o = getOrientation(polygon[i], polygon[next], p);
        
        flag |= o;
        
        if(flag == 3) return false;
    }
    
    return true;
}


int main()
{
    int N;
    cin >> N; cin.ignore();
    
    vector<Point> polygon;
    
    for (int i = 0; i < N; i++) {
        int x;
        int y;
        cin >> x >> y; cin.ignore();
        
        polygon.push_back({x, y});
    }
    
    int M;
    cin >> M; cin.ignore();
    
    for (int i = 0; i < M; i++) {
        int x;
        int y;
        cin >> x >> y; cin.ignore();
        
        if(isInside(polygon, {x, y})) cout<<"hit\n";
        else cout<<"miss\n";
        
    }

}