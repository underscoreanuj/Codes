class Solution
{
public:
    int jump(vector<int> &nums)
    {
        int n = nums.size();
        if (n <= 1)
            return 0;

        int jumps = 0, cur = 0, end = 0;
        for (int i = 0; i < n; ++i)
        {
            end = max(end, i + nums[i]);
            if (i == cur)
            {
                cur = end;
                ++jumps;
                if (cur >= n - 1)
                    break;
            }
        }

        return jumps;
    }
};