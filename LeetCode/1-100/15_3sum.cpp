class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        vector<vector<int>> ret;
        if (nums.size() == 0)
            return ret;

        int n = nums.size(), tx = 0;
        sort(nums.begin(), nums.end());

        if (3 * nums[n - 1] < 0)
            return ret;

        for (int i = 0; i < n; ++i)
        {
            if (nums[i] + 2 * nums[n - 1] < 0)
                continue;
            int target = -nums[i];
            int l = i + 1, r = n - 1;
            while (l < r)
            {
                tx = nums[l] + nums[r];
                if (tx == target)
                {
                    ret.push_back({nums[i], nums[l], nums[r]});
                    ++l;
                    while (l < n - 1 && nums[l] == nums[l - 1])
                        ++l;
                    --r;
                    while (r >= 0 && nums[r] == nums[r + 1])
                        --r;
                }
                else if (tx < target)
                {
                    ++l;
                    while (l < n - 1 && nums[l] == nums[l - 1])
                        ++l;
                }
                else
                {
                    --r;
                    while (r >= 0 && nums[r] == nums[r + 1])
                        --r;
                }
            }
            while (i + 1 < n && nums[i] == nums[i + 1])
                ++i;
        }

        return ret;
    }
};