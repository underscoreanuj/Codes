// easier to understand solution

class Solution
{
public:
    int largestRectangleArea(vector<int> &heights)
    {
        int n = heights.size(), cur = 0, result = 0;
        vector<int> left(n, 0), right(n, 0);

        for (int i = 0; i < n; ++i)
        {
            cur = i - 1;
            while (cur >= 0 && heights[cur] >= heights[i])
                cur = left[cur];
            left[i] = cur;
        }

        for (int i = n - 1; i >= 0; --i)
        {
            cur = i + 1;
            while (cur < n && heights[cur] >= heights[i])
                cur = right[cur];
            right[i] = cur;
        }

        for (int i = 0; i < n; ++i)
            result = max(result, heights[i] * (right[i] - left[i] - 1));

        return result;
    }
};

auto speedup = []() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

// stack based solution

class Solution
{
public:
    int largestRectangleArea(vector<int> &heights)
    {
        heights.emplace_back(0);
        int n = heights.size(), h = 0, w = 0, result = 0;
        stack<int> S;
        S.push(-1);

        for (int i = 0; i < n; ++i)
        {
            while (S.size() > 1 && heights[i] < heights[S.top()])
            {
                h = heights[S.top()];
                S.pop();
                w = i - S.top() - 1;
                result = max(result, h * w);
            }
            S.push(i);
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
