// a better dp approach

// extension of largest rectangle in histogram

class Solution
{
public:
    int maximalRectangleUtil(vector<int> &heights)
    {
        int result = 0, cur = 0;
        stack<int> S;
        S.push(-1);

        for (int i = 0; i < heights.size(); ++i)
        {
            while (S.size() > 1 && heights[i] < heights[S.top()])
            {
                cur = S.top();
                S.pop();
                result = max(result, (i - (S.top() + 1)) * heights[cur]);
            }
            S.push(i);
        }

        return result;
    }

    int maximalRectangle(vector<vector<char>> &matrix)
    {
        if (matrix.empty())
            return 0;

        int m = matrix.size(), n = matrix[0].size();
        vector<int> heights(n + 1, 0);
        int result = 0;

        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (matrix[i][j] == '1')
                    ++heights[j];
                else
                    heights[j] = 0;
            }
            result = max(result, maximalRectangleUtil(heights));
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