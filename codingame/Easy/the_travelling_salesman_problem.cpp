#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

class Point
{
public:
    int x;
    int y;

    Point(int x, int y)
    {
        this->x = x;
        this->y = y;
    }
};

double getDist(Point a, Point b)
{
    return sqrt(pow((b.x - a.x), 2) + pow((b.y - a.y), 2));
}

int main()
{
    int N;
    cin >> N;
    cin.ignore();

    vector<Point> cities;
    vector<bool> vis(N, false);

    for (int i = 0; i < N; i++)
    {
        int X;
        int Y;
        cin >> X >> Y;
        cin.ignore();

        cities.push_back({X, Y});
    }

    int idx = 0;
    double min_dist = 999999, total_dist = 0;
    int min_idx = 0;
    bool flag = false;
    int X = N;

    while (X--)
    {
        min_dist = 999999;

        flag = false;
        for (int i = 0; i < N; ++i)
        {

            if (i != idx && !vis[i])
            {
                double dd = getDist(cities[idx], cities[i]);
                if (min_dist > dd)
                {
                    min_dist = dd;
                    min_idx = i;
                    flag = true;
                }
            }
        }

        if (flag)
        {
            total_dist += min_dist;
            vis[idx] = true;
            idx = min_idx;
        }
        else
        {
            total_dist += getDist(cities[idx], cities[0]);
            break;
        }
    }
    cout << fixed << setprecision(0) << total_dist << "\n";
}