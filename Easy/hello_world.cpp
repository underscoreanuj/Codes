#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

#define EARTH_RADIUS 6371

class City
{
public:
    string msg;
    long double lat;
    long double lon;
    City(string lat, string lon)
    {
        this->lat = this->getDecimal(lat);
        this->lon = this->getDecimal(lon);
    }

    long double getDecimal(string sg)
    {
        char dir = sg[0];
        long double degree, minutes, arc_minutes;
        if (dir == 'N' || dir == 'S')
        {
            degree = stod(sg.substr(1, 2));
            minutes = stod(sg.substr(3, 2));
            arc_minutes = stod(sg.substr(5, 2));
        }
        else
        {
            degree = stod(sg.substr(1, 3));
            minutes = stod(sg.substr(4, 2));
            arc_minutes = stod(sg.substr(6, 2));
        }

        minutes += arc_minutes / 60.0;
        degree += minutes / 60.0;

        if (dir == 'W' || dir == 'S')
            degree *= -1;
        return degree;
    }

    long double toRadian(long double degree)
    {
        return degree * 0.0174533;
    }

    int getDistance(string l_lat, string l_lon)
    {
        long double lt = this->getDecimal(l_lat);
        long double ln = this->getDecimal(l_lon);

        long double lat1 = this->toRadian(this->lat);
        long double lat2 = this->toRadian(lt);
        long double delta_lat = this->toRadian(abs(this->lat - lt));
        long double delta_lon = this->toRadian(abs(ln - this->lon));

        // long double d = acos(sin(lat1)*sin(lat2) + cos(lat1)*cos(lat2)*cos(delta_lon));
        // long double dist = d*EARTH_RADIUS;

        long double a = sin(delta_lat / 2.0) * sin(delta_lat / 2.0) + cos(lat1) * cos(lat2) * sin(delta_lon / 2.0) * sin(delta_lon / 2.0);
        long double c = 2 * atan2(sqrt(a), sqrt(1 - a));
        long double dist = EARTH_RADIUS * c;

        return round(dist);
    }
};

int main()
{
    int n; // number of capitals
    cin >> n;
    cin.ignore();
    int m; // number of geolocations for which to find the closest capital
    cin >> m;
    cin.ignore();

    vector<City> cities;
    map<size_t, vector<City>> op;

    for (int i = 0; i < n; i++)
    {
        string cityName, lat, lon;
        cin >> cityName >> lat >> lon;
        cin.ignore();

        cities.push_back({lat, lon});
    }

    for (int i = 0; i < n; i++)
    {
        string message;
        getline(cin, message);

        cities[i].msg = message;
    }

    for (int i = 0; i < m; i++)
    {
        string l_lat, l_lon;
        cin >> l_lat >> l_lon;
        cin.ignore();

        op.clear();

        for (auto c : cities)
        {
            int dist = c.getDistance(l_lat, l_lon);
            op[dist].push_back(c);
        }

        auto it = op.begin();
        vector<City> mesg = it->second;

        for (int i = 0; i < mesg.size(); ++i)
        {
            if (i + 1 < mesg.size())
                cout << mesg[i].msg << " ";
            else
                cout << mesg[i].msg;
        }

        cout << "\n";
    }
}