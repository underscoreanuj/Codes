#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

int main()
{
    int speed;
    cin >> speed;
    cin.ignore();
    int lightCount;
    cin >> lightCount;
    cin.ignore();

    vector<pair<int, int>> lights;

    for (int i = 0; i < lightCount; i++)
    {
        int distance;
        int duration;
        cin >> distance >> duration;
        cin.ignore();
        lights.push_back({distance, duration});
    }

    bool flag = true;

    for (int i = speed; i >= 1; --i)
    {
        flag = true;

        for (int j = 0; j < lights.size(); ++j)
        {
            int tm = (lights[j].first * 18) / (i * 5);
            if (tm % (2 * lights[j].second) >= lights[j].second)
            {
                flag = false;
                break;
            }
        }
        if (flag)
        {
            cout << i << "\n";
            return 0;
        }
    }

    cout << "0" << endl;
}