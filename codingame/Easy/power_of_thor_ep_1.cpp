#include <iostream>
#include <string>
#include <vector>
#include <algorithm>


using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 * ---
 * Hint: You can use the debug stream to print initialTX and initialTY, if Thor seems not follow your orders.
 **/

int getDir(int src, int dest) {
    if(dest == src) return 0;
    if(dest > src) return 1;
    if(dest < src) return -1;
}

int main()
{
    int lightX; // the X position of the light of power
    int lightY; // the Y position of the light of power
    int initialTX; // Thor's starting X position
    int initialTY; // Thor's starting Y position
    cin >> lightX >> lightY >> initialTX >> initialTY; cin.ignore();


    // game loop
    while (1) {
        int remainingTurns; // The remaining amount of turns Thor can move. Do not remove this line.
        cin >> remainingTurns; cin.ignore();
        
        int x = getDir(initialTX, lightX);
        int y = getDir(initialTY, lightY);
        

        if(x == 0) {
            if(y == 1) { 
                cout<<"S"<<endl;
                ++initialTY;
            }
            else if(y == -1) { 
                cout<<"N"<<endl;
                --initialTY;
            }
        }
        else if(y == 0) {
            if(x == 1) {
                cout<<"E"<<endl;
                ++initialTX;
            }
            else if(x == -1) {
                cout<<"W"<<endl;
                --initialTX;
            }
        }
        else if(x == 1 && y == -1) {
            cout<<"NE"<<endl;
            --initialTY;
            ++initialTX;
        }
        else if(x == -1 && y == -1) { 
            cout<<"NW"<<endl;
            --initialTY;
            --initialTX;
        }
        else if(x == -1 && y == 1) {
            cout<<"SW"<<endl;
            ++initialTY;
            --initialTX;
        }
        else if(x == 1 && y == 1) {
            cout<<"SE"<<endl;
            ++initialTY;
            ++initialTX;
        }
        // A single line providing the move to be made: N NE E SE S SW W or NW
        // cout << "SE" << endl;
        cerr<<initialTX<<" : "<<initialTY<<"\n";
    }
}