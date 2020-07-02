class Solution
{
public:
    bool canJump(vector<int> &nums)
    {
        int n = nums.size();
        if (n <= 1)
            return true;

        int farthest = 0;
        for (int i = 0; i < n; ++i)
        {
            if (i > farthest)
                return false;
            farthest = max(farthest, i + nums[i]);
        }

        return true;
    }
};