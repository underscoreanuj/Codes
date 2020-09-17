class Solution
{
public:
    bool isRobotBounded(string instructions)
    {
        int dir = 0, x = 0, y = 0;
        vector<pair<int, int>> delta = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

        for (char &c : instructions)
        {
            if (c == 'R')
                dir = (dir + 1) % 4;
            else if (c == 'L')
                dir = (4 + dir - 1) % 4;
            else
            {
                x += delta[dir].first;
                y += delta[dir].second;
            }
        }

        return (x == 0 && y == 0) || (dir != 0);
    }
};

auto speedup = []() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();