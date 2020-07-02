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
    int W; // width of the building.
    int H; // height of the building.
    cin >> W >> H; cin.ignore();
    int N; // maximum number of turns before game over.
    cin >> N; cin.ignore();
    int X0;
    int Y0;
    cin >> X0 >> Y0; cin.ignore();
    
    int start_x = 0, start_y = 0;
    int end_x = W, end_y = H;

    // game loop
    while (1) {
        string bombDir; // the direction of the bombs from batman's current location (U, UR, R, DR, D, DL, L or UL)
        cin >> bombDir; cin.ignore();
        
        if(bombDir == "U") {
            end_y = Y0;
            Y0 = (Y0+start_y)/2;
        }
        else if(bombDir == "D") {
            start_y = Y0;
            Y0 = (Y0+end_y)/2;
        }
        else if(bombDir == "L") {
            end_x = X0;
            X0 = (X0+start_x)/2;
        }
        else if(bombDir == "R") {
            start_x = X0;
            X0 = (X0+end_x)/2;
        }
        else if(bombDir == "DL") {
            start_y = Y0;
            end_x = X0;
            Y0 = (Y0+end_y)/2;
            X0 = (X0+start_x)/2;
        }
        else if(bombDir == "DR") {
            start_y = Y0;
            start_x = X0;
            Y0 = (Y0+end_y)/2;
            X0 = (X0+end_x)/2;
        }
        else if(bombDir == "UL") {
            end_y = Y0;
            end_x = X0;
            Y0 = (Y0+start_y)/2;
            X0 = (X0+start_x)/2;
        }
        else if(bombDir == "UR") {
            end_y = Y0;
            start_x = X0;
            Y0 = (Y0+start_y)/2;
            X0 = (X0+end_x)/2;
        }
        
        cout<<X0<<" "<<Y0<<"\n";
        
    }
}