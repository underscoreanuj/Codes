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

string getPos(int row, int col)
{
    string ret(1, col + 'a');
    ret += (8 - row) + '0';

    return ret;
}

void posToIdx(string pos, int &row, int &col)
{
    col = pos[0] - 'a';
    row = 8 - (pos[1] - '0');
}

int main()
{
    string rookPosition;
    cin >> rookPosition;
    cin.ignore();
    int nbPieces;
    cin >> nbPieces;
    cin.ignore();

    vector<string> result;
    unordered_map<string, int> oPieces;
    vector<string> kills;

    int i = 0, j = 0;
    posToIdx(rookPosition, i, j);

    int row_left = 0, row_right = 7, col_up = 0, col_down = 7;
    int t_x = 0, t_y = 0;

    for (int ind = 0; ind < nbPieces; ind++)
    {
        int colour;
        string onePiece;
        cin >> colour >> onePiece;
        cin.ignore();
        oPieces.insert({onePiece, colour});

        posToIdx(onePiece, t_x, t_y);

        if (t_x == i)
        { // same row
            if (t_y < j)
            { // to the left of rook
                if (colour == 0)
                    ++t_y;
                row_left = max(row_left, t_y);
            }
            else
            { // to the right of rook
                if (colour == 0)
                    --t_y;
                row_right = min(row_right, t_y);
            }
        }
        else if (t_y == j)
        { // same col
            if (t_x < i)
            { // above the rook
                if (colour == 0)
                    ++t_x;
                col_up = max(col_up, t_x);
            }
            else
            { // below the rook
                if (colour == 0)
                    --t_x;
                col_down = min(col_down, t_x);
            }
        }
    }

    cerr << row_left << " :: " << row_right << " -> " << col_up << " :: " << col_down << "\n";

    for (int cols = row_left; cols <= row_right; ++cols)
    {
        if (cols == j)
        { // consider all rows
            for (int rows = col_down; rows >= col_up; --rows)
            {
                if (rows == i)
                    continue;

                // row -> rows
                // col -> cols
                string op = getPos(rows, cols);
                if (oPieces.find(op) == oPieces.end())
                    cout << "R" << rookPosition << "-" << op << "\n";
                else if (oPieces[op] == 1)
                    kills.push_back("R" + rookPosition + "x" + op);
            }
        }
        else
        {
            // row -> i
            // col -> cols
            string op = getPos(i, cols);
            if (oPieces.find(op) == oPieces.end())
                cout << "R" << rookPosition << "-" << op << "\n";
            else if (oPieces[op] == 1)
                kills.push_back("R" + rookPosition + "x" + op);
        }
    }

    for (auto k : kills)
        cout << k << "\n";
}