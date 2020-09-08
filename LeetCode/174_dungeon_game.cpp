class Solution
{
public:
    int calculateMinimumHP(vector<vector<int>> &dungeon)
    {
        int rows = dungeon.size();
        int cols = dungeon[0].size();

        vector<vector<int>> tab(rows, vector<int>(cols, 0));

        for (int i = rows - 1; i >= 0; --i)
        {
            for (int j = cols - 1; j >= 0; --j)
            {
                if (i == rows - 1 && j == cols - 1)
                    tab[i][j] = max(1, 1 - dungeon[i][j]);
                else if (i == rows - 1)
                {
                    tab[i][j] = max(1, tab[i][j + 1] - dungeon[i][j]);
                }
                else if (j == cols - 1)
                {
                    tab[i][j] = max(1, tab[i + 1][j] - dungeon[i][j]);
                }
                else
                {
                    tab[i][j] = max(1, min(tab[i + 1][j], tab[i][j + 1]) - dungeon[i][j]);
                }
            }
        }

        return tab[0][0];
    }
};

auto speedup = []() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();