class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        int l = 0, r = height.size() - 1;
        int max_area = -1;

        while (l < r)
        {
            max_area = max(max_area, min(height[l], height[r]) * (r - l));

            if (height[l] > height[r])
                --r;
            else
                ++l;
        }

        return max_area;
    }
};