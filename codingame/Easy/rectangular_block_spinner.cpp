#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

void transpose(vector<string> &g)
{
    for (int i = 0; i < g.size() - 1; ++i)
    {
        for (int j = i + 1; j < g[i].size(); ++j)
        {
            swap(g[i][j], g[j][i]);
        }
    }
}

void reverseRows(vector<string> &g)
{
    for (int i = 0; i < g.size(); ++i)
        reverse(g[i].begin(), g[i].end());
}

void rotateLeft(vector<string> &g)
{
    reverseRows(g);
    transpose(g);
}

void rotateRight(vector<string> &g)
{
    transpose(g);
    reverseRows(g);
}

void printPat(vector<string> g)
{
    int n = g.size();
    int num_spaces = g.size() - 1;
    int ct = 1;

    while (ct <= n)
    {
        for (int i = 0; i < num_spaces; ++i)
            cout << " ";
        int j = 0;
        for (int i = ct - 1; i >= 0; --i)
        {
            cout << g[i][j];
            if (i > 0)
                cout << " ";
            ++j;
        }
        for (int i = 0; i < num_spaces; ++i)
            cout << " ";
        cout << "\n";
        ++ct;
        --num_spaces;
    }
    ct -= 2;
    num_spaces = 1;

    while (ct > 0)
    {
        for (int i = 0; i < num_spaces; ++i)
            cout << " ";
        int j = n - ct;
        for (int i = n - 1; i > n - ct - 1; --i)
        {
            cout << g[i][j];
            if (i > n - ct)
                cout << " ";
            ++j;
        }
        for (int i = 0; i < num_spaces; ++i)
            cout << " ";
        cout << "\n";
        --ct;
        ++num_spaces;
    }
}

int main()
{
    int size;
    cin >> size;
    cin.ignore();
    int angle;
    cin >> angle;
    cin.ignore();

    vector<string> grid(size);
    angle %= 360;
    int rot_ct = angle / 45;

    for (int i = 0; i < size; i++)
    {
        string p;
        for (int i = 0; i < size; ++i)
        {
            char c;
            cin >> c;
            p += c;
        }
        grid[i] = p;
    }

    switch (rot_ct)
    {
    case 1:
        rotateLeft(grid);
        break;
    case 3:
        rotateRight(grid);
        rotateRight(grid);
        break;
    case 5:
        rotateRight(grid);
        break;
    default:
        break;
    }

    printPat(grid);
}