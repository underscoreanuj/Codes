#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
 
double stringToDouble(string s) {
    if(s.find(",") != string::npos)
        s.replace(s.find(","), 1, ".");
    return stod(s);
}

string getSplit(string s, int c) {
    int ind = -1;
    while(c--) {
        ind = s.find(";", ind+1);
    }
    if(s.find(";", ind+1) != string::npos)
        return s.substr(ind+1, s.find(";", ind+1) - ind-1);
    else
        return  s.substr(ind+1, s.length()-ind);
        
    
    return "0,0";
}

double getDist(double lat_a, double lon_a, double lat_b, double lon_b) {
    double x = (lon_b - lon_a) * cos((lat_a + lat_b)/2);
    double y = lat_b - lat_a;
    return sqrt(x*x + y*y) * 6371;
}

int main()
{
    string LON;
    cin >> LON; cin.ignore();
    string LAT;
    cin >> LAT; cin.ignore();
    
    double lon = stringToDouble(LON);
    double lat = stringToDouble(LAT);
    
    
    int N;
    cin >> N; cin.ignore();
    
    string op;
    double t_lon, t_lat, t_dist, min_dist = 999999;
    
    
    for (int i = 0; i < N; i++) {
        string DEFIB;
        getline(cin, DEFIB);
        
        t_lon = stringToDouble(getSplit(DEFIB, 4));
        t_lat = stringToDouble(getSplit(DEFIB, 5));
        
        t_dist = getDist(lat, lon, t_lat, t_lon);
        if(t_dist < min_dist) {
            min_dist = t_dist;
            op = getSplit(DEFIB, 1);
        }
    }

    cout << op << endl;
}