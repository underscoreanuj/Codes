class Solution
{
public:
    int trap(vector<int> &height)
    {
        int total = 0;
        int l = 0, r = height.size() - 1, left = 0, right = 0;
        while (l <= r)
        {
            left = max(left, height[l]);
            right = max(right, height[r]);
            if (left < right)
            {
                total += left - height[l];
                ++l;
            }
            else
            {
                total += right - height[r];
                --r;
            }
        }

        return total;
    }
};