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

int main()
{
    int ROUNDS;
    cin >> ROUNDS;
    cin.ignore();
    int CASH;
    cin >> CASH;
    cin.ignore();

    double bet_cash, cash = CASH;

    for (int i = 0; i < ROUNDS; i++)
    {

        bet_cash = ceil(cash / 4.0);

        int res, bet;
        string PLAY;
        cin >> res >> PLAY;
        if (PLAY == "PLAIN")
        {
            cin >> bet;
            if (res == bet)
                bet_cash = bet_cash * 35;
            else
                bet_cash = -1 * bet_cash;
        }
        else if (PLAY == "ODD")
        {
            if (res % 2 == 0)
                bet_cash *= -1;
        }
        else
        {
            if (res % 2 != 0 || res == 0)
                bet_cash *= -1;
        }

        cash += bet_cash;
    }

    cout << cash << "\n";
}