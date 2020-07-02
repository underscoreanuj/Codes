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
    int nbFloors;              // number of floors
    int width;                 // width of the area
    int nbRounds;              // maximum number of rounds
    int exitFloor;             // floor on which the exit is found
    int exitPos;               // position of the exit on its floor
    int nbTotalClones;         // number of generated clones
    int nbAdditionalElevators; // ignore (always zero)
    int nbElevators;           // number of elevators
    cin >> nbFloors >> width >> nbRounds >> exitFloor >> exitPos >> nbTotalClones >> nbAdditionalElevators >> nbElevators;
    cin.ignore();

    unordered_map<int, int> E;

    for (int i = 0; i < nbElevators; i++)
    {
        int elevatorFloor; // floor on which this elevator is found
        int elevatorPos;   // position of the elevator on its floor
        cin >> elevatorFloor >> elevatorPos;
        cin.ignore();
        E.insert({elevatorFloor, elevatorPos});
    }

    // game loop
    while (1)
    {
        int cloneFloor;   // floor of the leading clone
        int clonePos;     // position of the leading clone on its floor
        string direction; // direction of the leading clone: LEFT or RIGHT
        cin >> cloneFloor >> clonePos >> direction;
        cin.ignore();

        int ePos = E[cloneFloor];
        if (cloneFloor == exitFloor)
            ePos = exitPos;
        if (clonePos < ePos)
        { // elevator to the right
            if (direction == "RIGHT")
                cout << "WAIT\n";
            else
            {
                cout << "BLOCK\n";
            }
        }
        else if (clonePos > ePos)
        { // elevator to the left
            if (direction == "LEFT")
                cout << "WAIT\n";
            else
            {
                cout << "BLOCK\n";
            }
        }
        else
            cout << "WAIT\n";
    }
}