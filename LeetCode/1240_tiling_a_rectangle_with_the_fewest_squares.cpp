// more efficient backtracking solution (uses 1d vector to store heights of squares and extra greedy method to prune the search space)

class Solution
{
public:
    int getLargestSquare(vector<int> &heights, int &idx, int &n)
    {
        // find the height of largest square that can fit starting from idx
        int len = 1;
        while (idx + len < heights.size() && heights[idx] + len < n && heights[idx + len] == heights[idx])
            ++len;

        return len;
    }

    void cover(vector<int> &heights, int &idx, int &len, bool cover)
    {
        // cover all heights from idx -> len with an increment in height of len
        for (int i = idx; i < idx + len; ++i)
            heights[i] += cover ? len : -len;
    }

    void backtrack(vector<int> &heights, int &n, int &result, int count = 0)
    {
        if (count >= result)
            return;

        int idx = 0;
        // find top-left-most uncovered block
        for (int i = 1; i < heights.size(); ++i)
        {
            if (heights[i] < heights[idx])
            {
                idx = i;
            }
        }

        // if all blocks are covered
        if (heights[idx] == n)
        {
            result = min(result, count);
            return;
        }

        // find the largest possible square that fits
        int len = getLargestSquare(heights, idx, n);

        // backtrack for all possible lengths
        for (int i = len; i >= 1; --i)
        {
            cover(heights, idx, i, true);
            backtrack(heights, n, result, count + 1);
            cover(heights, idx, i, false);
        }
    }

    int getGeneralSolution(int n, int m)
    {
        int ct = 1;
        while (m != n)
        {
            if (n < m)
                m -= n;
            else
                n -= m;
            ++ct;
        }

        return ct;
    }

    int tilingRectangle(int n, int m)
    {
        if (m == n)
            return 1;
        if (n < m)
            return tilingRectangle(m, n);

        vector<int> heights(m, 0);
        int result = getGeneralSolution(n, m);

        backtrack(heights, n, result);

        return result;
    }
};

auto speedup = []() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

// simple backtracking solution (uses 2d matrix of nxm)

class Solution
{
public:
    int getLargestSquare(vector<vector<int>> &grid, int x, int y)
    {
        // starting from (x, y) return the size of largest valid square possible
        int len = 1;

        while (x + len < grid.size() && y + len < grid[0].size())
        {
            for (int i = 0; i <= len; ++i)
            {
                if (grid[x + i][y + len] || grid[x + len][y + i])
                    return len;
            }
            ++len;
        }

        return len;
    }

    void cover(vector<vector<int>> &grid, int x, int y, int len, int val)
    {
        // fill a square of size => len with value => val starting from position (x, y)
        for (int i = x; i < x + len; ++i)
            for (int j = y; j < y + len; ++j)
                grid[i][j] = val;
    }

    void backtrack(vector<vector<int>> &grid, int &result, int count = 0)
    {
        if (count > result)
            return;

        int x = -1, y = -1;
        // find top-left-most uncovered block
        for (int i = 0; i < grid.size(); ++i)
        {
            for (int j = 0; j < grid[i].size(); ++j)
            {
                if (grid[i][j] == 0)
                {
                    x = i;
                    y = j;
                    break;
                }
            }
            if (x != -1 && y != -1)
                break;
        }

        // if all blocks are covered
        if (x == -1 && y == -1)
        {
            result = min(result, count);
            return;
        }

        // find the largest possible square that fits
        int len = getLargestSquare(grid, x, y);

        // backtrack for all possible lengths
        for (int i = len; i >= 1; --i)
        {
            cover(grid, x, y, i, 1);
            backtrack(grid, result, count + 1);
            cover(grid, x, y, i, 0);
        }
    }

    int tilingRectangle(int n, int m)
    {
        vector<vector<int>> grid(n, vector<int>(m, 0));
        int result = INT_MAX;

        backtrack(grid, result);

        return result;
    }
};

auto speedup = []() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();