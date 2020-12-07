class Solution
{
public:
    vector<vector<int>> spiralMatrixIII(int R, int C, int r0, int c0)
    {
        vector<vector<int>> result;
        vector<pair<int, int>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

        int count = 0, size = R * C, r = r0, c = c0, dir = 0, stride = 1, cur_len = 0;

        while (count < size)
        {
            if (r >= 0 && r < R && c >= 0 && c < C)
            {
                result.emplace_back(vector<int>{r, c});
                ++count;
            }
            if (cur_len == stride)
            {
                dir = (dir + 1) % 4;
                if (dir % 2 == 0)
                    ++stride;
                cur_len = 0;
            }

            r += dirs[dir].first;
            c += dirs[dir].second;

            ++cur_len;
        }

        return result;
    }
};

auto speedup = []() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();