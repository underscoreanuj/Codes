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

#define G 3.711
#define MAX_V_SPEED 40
#define MAX_H_SPEED 20
#define MAX_ANGLE 90
#define MAX_POW 4
#define RAD2DEG 57.29578

int main()
{
    int surfaceN; // the number of points used to draw the surface of Mars.
    cin >> surfaceN;
    cin.ignore();

    int start_x = -1, start_y = -1;
    int end_x = -1, end_y = -1;
    bool flag = true;

    for (int i = 0; i < surfaceN; i++)
    {
        int landX; // X coordinate of a surface point. (0 to 6999)
        int landY; // Y coordinate of a surface point. By linking all the points together in a sequential fashion, you form the surface of Mars.
        cin >> landX >> landY;
        cin.ignore();
        if (flag)
        {
            if (start_y == landY)
            {
                end_x = landX;
                end_y = landY;
                flag = false;
            }
            else
            {
                start_x = landX;
                start_y = landY;
            }
        }
    }

    int land_x = (start_x + end_x) / 2;
    int land_y = start_y;
    int landing_x, landing_y;
    // game loop
    while (1)
    {
        int X;
        int Y;
        int hSpeed; // the horizontal speed (in m/s), can be negative.
        int vSpeed; // the vertical speed (in m/s), can be negative.
        int fuel;   // the quantity of remaining fuel in liters.
        int rotate; // the rotation angle in degrees (-90 to 90).
        int power;  // the thrust power (0 to 4).
        cin >> X >> Y >> hSpeed >> vSpeed >> fuel >> rotate >> power;
        cin.ignore();

        int tAngle = 21;
        power = 4;
        rotate = 0;
        int speed = sqrt(hSpeed * hSpeed + vSpeed * vSpeed);

        if (X < start_x || X > end_x)
        {
            if ((X < start_x && hSpeed < 0) || (X > end_x && hSpeed > 0) || abs(hSpeed) > 4.2 * MAX_H_SPEED)
            { // too fast or in the wrong direction
                rotate = asin(((double)hSpeed / (double)speed)) * RAD2DEG;
            }
            else if (abs(hSpeed) < 2 * MAX_H_SPEED)
            { // too slow
                rotate = (X < start_x) ? -tAngle : (X > end_x) ? tAngle : 0;
            }
            else if (vSpeed >= 0)
            {
                power = 3;
            }
        }
        else
        {
            if (Y < 200 + land_y)
            {
                power = 4;
            }
            else if (abs(hSpeed) <= MAX_H_SPEED && abs(vSpeed) <= MAX_V_SPEED)
            {
                power = 3;
            }
            else
            {
                rotate = asin(((double)hSpeed / (double)speed)) * RAD2DEG;
            }
        }

        if ((abs(X - start_x) < 150 || abs(end_x - X) < 150) && Y > 500 + land_y)
        { // going beyond the surface to the other side
            if (asin(((double)hSpeed / (double)speed)) < 0)
                rotate = -30;
            else
                rotate = 30;
        }

        // rotate power. rotate is the desired rotation angle. power is the desired thrust power.
        cout << rotate << " " << power << endl;
    }
}