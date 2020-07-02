#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

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


double getDistance(Point a, Point b) {
    return sqrt(pow((b.x - a.x), 2) + pow((b.y - a.y), 2));
}


double isRightAngle(Point a, Point b, Point c) {
    return (b.x - a.x)*(c.x - b.x) + (b.y - a.y)*(c.y - b.y) == 0;
}

string whichQuad(Point a, Point b, Point c, Point d) {
    if(getDistance(a,b) == getDistance(c,d) && getDistance(b,c) == getDistance(d,a)) {
        if(isRightAngle(a, b, c)) { // not parallelogram/rhombus
            if(getDistance(a,b) == getDistance(b,c)) return "square";
            return "rectangle";
        }
        else {
            if(getDistance(a,b) == getDistance(b,c)) return "rhombus";
            return "parallelogram";
        }
    }
    return "quadrilateral";
}


int main()
{
    int n;
    cin >> n; cin.ignore();
    for (int i = 0; i < n; i++) {
        string A;
        int xA;
        int yA;
        string B;
        int xB;
        int yB;
        string C;
        int xC;
        int yC;
        string D;
        int xD;
        int yD;
        cin >> A >> xA >> yA >> B >> xB >> yB >> C >> xC >> yC >> D >> xD >> yD; cin.ignore();
        
        Point a(xA, yA);
        Point b(xB, yB);
        Point c(xC, yC);
        Point d(xD, yD);
        
        cout<<A<<B<<C<<D<<" is a "<<whichQuad(a,b,c,d)<<".\n";
        
    }

}