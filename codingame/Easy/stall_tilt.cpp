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

#define G 9.81
#define DEG2RAD 0.0174533

double getOptimalSpeed(double radius)
{
    return sqrt(tan(60 * DEG2RAD) * radius * G);
}

class SortFall
{
public:
    bool operator()(const pair<pair<char, int>, vector<int>> &o1, const pair<pair<char, int>, vector<int>> &o2)
    {
        if (o1.second.size() < o2.second.size())
            return true;
        if (o1.second.size() == o2.second.size())
            return o1.first.second > o2.first.second;
        if (o1.first.second > o2.first.second)
        {
            if (o1.second.size() > o2.second.size())
                return false;
            else if (o1.second.size() == o2.second.size())
            {
                if (o1.second.size() == 0)
                    return true;
                else
                {
                    int i = 0;
                    while (o1.second[i] == o2.second[i])
                        ++i;

                    return o1.second[i] > o2.second[i];
                }
            }
        }
        return false;
    }
};

int main()
{
    int n;
    cin >> n;
    cin.ignore();
    int v;
    cin >> v;
    cin.ignore();

    vector<pair<pair<char, int>, vector<int>>> players;

    for (int i = 0; i < n; i++)
    {
        int speed;
        cin >> speed;
        cin.ignore();
        players.push_back({{'a' + i, speed}, {}});
    }

    int max_o_speed = 999999;

    for (int i = 0; i < v; i++)
    {
        int bends;
        cin >> bends;
        cin.ignore();

        int o_speed = getOptimalSpeed(bends);
        max_o_speed = min(max_o_speed, o_speed);

        for (int j = 0; j < players.size(); ++j)
        {
            if (players[j].first.second > o_speed)
            {
                players[j].second.push_back(i);
            }
        }
    }

    sort(players.begin(), players.end(), SortFall());

    cout << max_o_speed << "\n";
    cout << "y\n";
    for (auto p : players)
    {
        cout << p.first.first << "\n";
    }
}