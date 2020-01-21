#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Don't let the machines win. You are humanity's last hope...
 **/

int main()
{
    int width; // the number of cells on the X axis
    cin >> width;
    cin.ignore();
    int height; // the number of cells on the Y axis
    cin >> height;
    cin.ignore();

    vector<string> grid(height);

    for (int i = 0; i < height; i++)
    {
        getline(cin, grid[i]); // width characters, each either 0 or .

        cerr << "\n ---   " << grid[i] << "\n";
    }

    for (int i = 0; i < height; ++i)
    {
        for (int j = 0; j < width; ++j)
        {
            if (grid[i][j] != '.')
            {
                cout << j << " " << i << " ";
                int pos = grid[i].find('0', j + 1);
                if (pos != string::npos)
                    cout << pos << " " << i << " ";
                else
                    cout << "-1 -1 ";
                int k = 0;
                for (k = i + 1; k < height; ++k)
                {
                    if (grid[k][j] == '0')
                        break;
                }
                if (k < height)
                    cout << j << " " << k << "\n";
                else
                    cout << "-1 -1\n";
            }
        }
    }
}