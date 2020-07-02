#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int getMaxFromIdx(vector<vector<int>> &grid, int row, int col)
{
    if (grid[row][col] == 0)
        return 0;

    int res = 1, max_res = -999999;

    if (col < 17)
    { // along the row horizontally
        for (int i = col; i < col + 4; ++i)
        {
            res *= grid[row][i];
            if (res == 0)
                break;
        }
        max_res = max(max_res, res);
    }

    if (row < 17)
    { // along the col vertically
        res = 1;
        for (int i = row; i < row + 4; ++i)
        {
            res *= grid[i][col];
            if (res == 0)
                break;
        }
        max_res = max(max_res, res);
    }

    if (row < 17 && col < 17)
    { // along the diagonal (down-right)
        res = 1;
        for (int i = 0; i < 4; ++i)
        {
            res *= grid[row + i][col + i];
            if (res == 0)
                break;
        }
        max_res = max(max_res, res);
    }

    if (row < 17 && col > 2)
    { // along the diagonal (down-left)
        res = 1;
        for (int i = 0; i < 4; ++i)
        {
            res *= grid[row + i][col - i];
            if (res == 0)
                break;
        }
        max_res = max(max_res, res);
    }

    return max_res;
}

int getLargestProductInGrid(vector<vector<int>> &grid)
{
    int max_res = 0;

    for (int i = 0; i < 20; ++i)
    {
        for (int j = 0; j <= 20; ++j)
        {
            max_res = max(max_res, getMaxFromIdx(grid, i, j));
        }
    }

    return max_res;
}

int main()
{
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    vector<vector<int>> grid(20, vector<int>(20, 0));

    for (int i = 0; i < 20; ++i)
    {
        for (int j = 0; j < 20; ++j)
            cin >> grid[i][j];
    }

    cout << getLargestProductInGrid(grid) << "\n";

    return 0;
}
