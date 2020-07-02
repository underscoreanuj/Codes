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

int main()
{

    unordered_map<int, unordered_map<int, int>> T = {
        {0, {{-1, 0}, {1, 0}, {-2, 0}, {2, 0}}},
        {1, {{-1, 1}, {1, 0}, {-2, 1}, {2, 1}}},
        {2, {{-1, 0}, {1, 0}, {-2, 2}, {2, -2}}},
        {3, {{-1, 1}, {1, 0}, {-2, 0}, {2, 0}}},
        {4, {{-1, -2}, {1, 0}, {-2, 0}, {2, 1}}},
        {5, {{-1, 2}, {1, 0}, {-2, 1}, {2, 0}}},
        {6, {{-1, 0}, {1, 0}, {-2, 2}, {2, -2}}},
        {7, {{-1, 1}, {1, 0}, {-2, 0}, {2, 1}}},
        {8, {{-1, 0}, {1, 0}, {-2, 1}, {2, 1}}},
        {9, {{-1, 1}, {1, 0}, {-2, 1}, {2, 0}}},
        {10, {{-1, -2}, {1, 0}, {-2, 0}, {2, 0}}},
        {11, {{-1, 2}, {1, 0}, {-2, 0}, {2, 0}}},
        {12, {{-1, 0}, {1, 0}, {-2, 0}, {2, 1}}},
        {13, {{-1, 0}, {1, 0}, {-2, 1}, {2, 0}}},
    };

    int W; // number of columns.
    int H; // number of rows.
    cin >> W >> H;
    cin.ignore();

    vector<vector<int>> g(H);

    for (int i = 0; i < H; i++)
    {
        g[i] = vector<int>(W, 0);
        for (int j = 0; j < W; ++j)
            cin >> g[i][j];
    }

    int EX; // the coordinate along the X axis of the exit (not useful for this first mission, but must be read).
    cin >> EX;
    cin.ignore();

    int prev = -1;

    // game loop
    while (1)
    {
        int XI;
        int YI;
        string POS;
        cin >> XI >> YI >> POS;
        cin.ignore();

        if (POS == "TOP")
            prev = -1;
        if (POS == "LEFT")
            prev = -2;
        if (POS == "RIGHT")
            prev = 2;

        int type = g[YI][XI];
        int next = T[type][prev];

        if (next == 2)
        { // to the right
            prev = -2;
            ++XI;
        }
        else if (next == -2)
        { // to the left
            prev = 2;
            --XI;
        }
        else if (next == 1)
        { // down
            prev = -1;
            ++YI;
        }

        // One line containing the X Y coordinates of the room in which you believe Indy will be on the next turn.
        cout << XI << " " << YI << endl;
    }
}