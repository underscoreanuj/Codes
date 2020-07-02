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

    vector<int> bowls(14, 0);

    for (int i = 0; i < 14; ++i)
    {
        cin >> bowls[i];
    }

    int num;
    cin >> num;
    cin.ignore();

    num += 8;
    int grains = bowls[num - 1];
    bowls[num - 1] = 0;

    while (grains)
    {
        if (num == 6)
            ++num;
        ++bowls[num];
        num = (num + 1) % 14;
        --grains;
    }

    for (int i = 0; i < 14; ++i)
    {
        if (i == 6 || i == 13)
            cout << "[" << bowls[i] << "]\n";
        else
            cout << bowls[i] << " ";
    }

    if (num == 0)
        cout << "REPLAY";
}