class Solution
{
public:
    bool checkStraightLine(vector<vector<int>> &coordinates)
    {
        if (coordinates.size() <= 2)
            return true;

        int a = 0, b = 0;
        for (int i = 1; i < coordinates.size() - 1; ++i)
        {
            a = (coordinates[i + 1][0] - coordinates[0][0]) * (coordinates[i][1] - coordinates[0][1]);
            b = (coordinates[i][0] - coordinates[0][0]) * (coordinates[i + 1][1] - coordinates[0][1]);

            if (a != b)
                return false;
        }

        return true;
    }
};

auto speedup = []() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();