class Solution
{
public:
    int threeSumClosest(vector<int> &nums, int target)
    {
        int ret = 0, min_diff = 999999;
        sort(nums.begin(), nums.end());
        int n = nums.size(), tx = 0, diff;

        for (int i = 0; i < nums.size(); ++i)
        {
            int l = i + 1, r = n - 1;
            while (l < r)
            {
                tx = nums[i] + nums[l] + nums[r];
                if (tx == target)
                    return target;
                diff = abs(tx - target);
                if (min_diff > diff)
                {
                    min_diff = diff;
                    ret = tx;
                }
                if (tx < target)
                {
                    ++l;
                    while (l < r && nums[l] == nums[l - 1])
                        ++l;
                }
                else
                {
                    --r;
                    while (r > l && nums[r] == nums[r + 1])
                        --r;
                }
            }
        }

        return ret;
    }
};