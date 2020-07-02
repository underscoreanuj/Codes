#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

int processCard(string card)
{
    if (card[0] == 'J')
        return 11;
    if (card[0] == 'Q')
        return 12;
    if (card[0] == 'K')
        return 13;
    if (card[0] == 'A')
        return 14;
    int i = 0;
    while (isdigit(card[i]))
        ++i;
    return stoi(card.substr(0, i));
}

int Fight(queue<int> &P1, queue<int> &P2, queue<int> &t1, queue<int> &t2, bool war = false)
{
    if (war && (P1.size() == 0 || P2.size() == 0))
        return 0;

    int p1_c = P1.front();
    int p2_c = P2.front();
    P1.pop();
    P2.pop();
    t1.push(p1_c);
    t2.push(p2_c);

    if (p1_c > p2_c)
    { // player 1 wins
        return 1;
    }
    else if (p1_c < p2_c)
    { // player 2 wins
        return 2;
    }
    else
    { // war
        for (int i = 0; i < 3; ++i)
        {
            t1.push(P1.front());
            t2.push(P2.front());
            P1.pop();
            P2.pop();
            if (P1.size() == 0 || P2.size() == 0)
                return 0;
        }

        return Fight(P1, P2, t1, t2, true);
    }
}

int main()
{
    int n; // the number of cards for player 1
    cin >> n;
    cin.ignore();

    queue<int> P1, P2, t1, t2;

    for (int i = 0; i < n; i++)
    {
        string cardp1; // the n cards of player 1
        cin >> cardp1;
        cin.ignore();
        P1.push(processCard(cardp1));
    }
    int m; // the number of cards for player 2
    cin >> m;
    cin.ignore();
    for (int i = 0; i < m; i++)
    {
        string cardp2; // the m cards of player 2
        cin >> cardp2;
        cin.ignore();
        P2.push(processCard(cardp2));
    }

    int num_rounds = 0, res;
    while (true)
    {
        ++num_rounds;
        res = Fight(P1, P2, t1, t2);
        if (res == 1)
        {
            if (P2.size() == 0)
                break;
            while (!t1.empty())
            {
                P1.push(t1.front());
                t1.pop();
            }
            while (!t2.empty())
            {
                P1.push(t2.front());
                t2.pop();
            }
        }
        else if (res == 2)
        {
            if (P1.size() == 0)
                break;
            while (!t1.empty())
            {
                P2.push(t1.front());
                t1.pop();
            }
            while (!t2.empty())
            {
                P2.push(t2.front());
                t2.pop();
            }
        }
        else
        {
            cout << "PAT\n";
            return 0;
        }
    }

    cout << res << " " << num_rounds << endl;
}