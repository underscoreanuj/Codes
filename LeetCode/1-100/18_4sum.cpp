class Solution
{
public:
    vector<vector<int>> ret;

    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        if (nums.size() == 0)
            return ret;

        int n = nums.size();
        sort(nums.begin(), nums.end());

        if (nums[n - 1] * 4 < target)
            return ret;

        for (int i = 0; i < nums.size(); ++i)
        {
            threeSum(nums, i + 1, target - nums[i]);
            while (i < n - 1 && nums[i] == nums[i + 1])
                ++i;
        }

        return ret;
    }

    void threeSum(vector<int> &nums, int ind, int target)
    {

        int n = nums.size();

        if (nums[n - 1] * 3 < target)
            return;

        for (int i = ind; i < n; ++i)
        {
            if (nums[n - 1] * 2 < target - nums[i])
                continue;

            int l = i + 1, r = n - 1;
            while (l < r)
            {
                int x = nums[i] + nums[l] + nums[r];
                if (x == target)
                {
                    ret.push_back({nums[ind - 1], nums[i], nums[l], nums[r]});
                    ++l;
                    --r;
                    while (l < r && nums[l] == nums[l - 1])
                        ++l;
                    while (r > l && nums[r] == nums[r + 1])
                        --r;
                }
                else if (x < target)
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
            while (i < n - 1 && nums[i] == nums[i + 1])
                ++i;
        }
    }
};