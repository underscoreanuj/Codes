class Solution
{
public:
    double getArea(int x0, int y0, int x1, int y1, int x2, int y2)
    {
        return 0.5 * abs(x0 * (y1 - y2) - y0 * (x1 - x2) + (x1 * y2 - x2 * y1));
    }

    double largestTriangleArea(vector<vector<int>> &points)
    {
        double max_area = 0;

        for (int i = 0; i < points.size(); ++i)
        {
            for (int j = i + 1; j < points.size(); ++j)
            {
                for (int k = j + 1; k < points.size(); ++k)
                {
                    max_area = max(max_area, getArea(points[i][0], points[i][1], points[j][0], points[j][1], points[k][0], points[k][1]));
                }
            }
        }

        return max_area;
    }
};

auto speedup = []() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();