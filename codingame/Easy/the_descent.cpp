#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * The while loop represents the game.
 * Each iteration represents a turn of the game
 * where you are given inputs (the heights of the mountains)
 * and where you have to print an output (the index of the mountain to fire on)
 * The inputs you are given are automatically updated according to your last actions.
 **/

int main()
{

    // game loop
    while (1) {
        int max_ind = 0, max_val = -999;
        for (int i = 0; i < 8; i++) {
            int mountainH; // represents the height of one mountain.
            cin >> mountainH; cin.ignore();
            if(mountainH > max_val) {
                max_val = mountainH;
                max_ind = i;
            }
        }

        cout << max_ind << endl; // The index of the mountain to fire on.
    }
}