#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

class Paths
{
public:
    int x;
    int y;
    int dir;
    Paths(int x, int y, int dir)
    {
        this->x = x;
        this->y = y;
        this->dir = dir;
    }

    bool operator==(const Paths &o) const
    {
        return (this->x == o.x && this->y == o.y && this->dir == o.dir);
    }
};

class MyHash
{
public:
    size_t operator()(const Paths &o) const
    {
        return (hash<int>()(o.x) ^ hash<int>()(o.y) ^ hash<int>()(o.dir));
    }
};

class Bender
{
public:
    bool dir_priority; // true-> anti-clockwise(default) else clockwise
    bool breaker_mode; // can break X

    Bender()
    {
        this->dir_priority = true;
        this->breaker_mode = false;
    }
};

string getDir(int x)
{
    if (x == 0)
        return "SOUTH";
    if (x == 1)
        return "EAST";
    if (x == 2)
        return "NORTH";
    if (x == 3)
        return "WEST";
}

string moveBender(int &x, int &y, int &start_dir, vector<string> &grid, bool &grid_changed, Bender b)
{
    static vector<pair<int, int>> dirs = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

    int next_dir = 1;
    if (!b.dir_priority)
        next_dir = 3;

    int t_x = x + dirs[start_dir].first;
    int t_y = y + dirs[start_dir].second;

    if (grid[t_x][t_y] != '#' && grid[t_x][t_y] != 'X')
    {
        x = t_x;
        y = t_y;
        return getDir(start_dir);
    }

    if (grid[t_x][t_y] == 'X' && b.breaker_mode)
    {
        grid[t_x][t_y] = ' ';
        grid_changed = true;
        x = t_x;
        y = t_y;
        return getDir(start_dir);
    }

    start_dir = b.dir_priority ? 0 : 3;

    for (int i = 0; i < 4; ++i)
    {
        t_x = x + dirs[start_dir].first;
        t_y = y + dirs[start_dir].second;

        if (grid[t_x][t_y] != '#' && grid[t_x][t_y] != 'X')
        {
            x = t_x;
            y = t_y;
            return getDir(start_dir);
        }

        if (grid[t_x][t_y] == 'X' && b.breaker_mode)
        {
            grid[t_x][t_y] == ' ';
            grid_changed = true;
            x = t_x;
            y = t_y;
            return getDir(start_dir);
        }

        start_dir = (start_dir + next_dir) % 4;
    }
}

int main()
{
    int L;
    int C;

    cin >> L >> C;
    cin.ignore();

    unordered_set<Paths, MyHash> prev_paths;
    bool grid_changed = false;

    int start_pos_x = 0, start_pos_y = 0, suicide_pos_x = 0, suicide_pos_y = 0;
    int t1_x = 0, t2_x = 0, t1_y = 0, t2_y = 0, start_dir = 0;

    bool start_found = false;
    bool suicide_found = false;
    bool teleporter_found = false;
    bool another_teleporter_found = false;

    vector<string> grid(L);
    for (int i = 0; i < L; i++)
    {
        getline(cin, grid[i]);

        if (!start_found)
        {
            int pos = grid[i].find('@');
            if (pos != string::npos)
            {
                start_pos_x = i;
                start_pos_y = pos;
                start_found = true;
            }
        }

        if (!suicide_found)
        {
            int pos = grid[i].find('$');
            if (pos != string::npos)
            {
                suicide_pos_x = i;
                suicide_pos_y = pos;
                suicide_found = true;
            }
        }

        if (!teleporter_found)
        {
            int pos = grid[i].find('T');
            if (pos != string::npos)
            {
                t1_x = i;
                t1_y = pos;
                teleporter_found = true;
            }
            // if both teleporters are in same row
            pos = grid[i].find('T', pos + 1);
            if (pos != string::npos)
            {
                t2_x = i;
                t2_y = pos;
                another_teleporter_found = true;
            }
        }

        else if (teleporter_found && !another_teleporter_found)
        {
            int pos = grid[i].find('T');
            if (pos != string::npos)
            {
                t2_x = i;
                t2_y = pos;
                another_teleporter_found = true;
            }
        }
    }

    Bender b;
    vector<string> op;

    while (true)
    {
        Paths obj(start_pos_x, start_pos_y, start_dir);
        if (prev_paths.find(obj) != prev_paths.end())
        {
            if (!grid_changed && !b.breaker_mode)
            {
                cout << "LOOP\n";
                return 0;
            }
            else
            {
                grid_changed = false;
                prev_paths.clear();
            }
        }

        prev_paths.insert(obj);

        if (start_pos_x == suicide_pos_x && start_pos_y == suicide_pos_y)
            break;
        if (start_pos_x == t1_x && start_pos_y == t1_y)
        {
            start_pos_x = t2_x;
            start_pos_y = t2_y;
        }
        else if (start_pos_x == t2_x && start_pos_y == t2_y)
        {
            start_pos_x = t1_x;
            start_pos_y = t1_y;
        }
        if (grid[start_pos_x][start_pos_y] == 'S')
            start_dir = 0;
        if (grid[start_pos_x][start_pos_y] == 'E')
            start_dir = 1;
        if (grid[start_pos_x][start_pos_y] == 'N')
            start_dir = 2;
        if (grid[start_pos_x][start_pos_y] == 'W')
            start_dir = 3;

        if (grid[start_pos_x][start_pos_y] == 'I')
            b.dir_priority = !b.dir_priority;
        if (grid[start_pos_x][start_pos_y] == 'B')
            b.breaker_mode = !b.breaker_mode;

        string dir = moveBender(start_pos_x, start_pos_y, start_dir, grid, grid_changed, b);
        op.push_back(dir);
    }

    for (auto o : op)
        cout << o << "\n";
}