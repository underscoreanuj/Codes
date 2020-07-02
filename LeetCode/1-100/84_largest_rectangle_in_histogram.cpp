class Solution
{
public:
    int largestRectangleArea(vector<int> &heights)
    {
        heights.push_back(0);
        stack<int> S;
        S.push(-1);
        int result = 0, cur = 0, prev = 0;

        for (int i = 0; i < heights.size(); ++i)
        {
            while (S.size() >= 2 && heights[i] < heights[S.top()])
            {
                cur = S.top();
                S.pop();
                prev = S.top();

                result = max(result, (i - (prev + 1)) * heights[cur]);
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