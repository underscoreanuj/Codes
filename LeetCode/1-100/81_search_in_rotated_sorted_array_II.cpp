class Solution
{
public:
    bool search(vector<int> &nums, int target)
    {
        if (nums.size() == 0)
            return false;

        int l = 0, r = nums.size() - 1, mid = 0, val = 0;

        if (nums[l] == nums[r])
        {
            while (r > l && nums[r] == nums[r - 1])
                --r;
        }

        while (l <= r)
        {
            mid = l + ((r - l >> 1));

            val = nums[mid] < nums[0] ? (target < nums[0] ? nums[mid] : 999999) : (target < nums[0] ? -999999 : nums[mid]);

            if (val == target)
                return true;
            else if (val < target)
                l = mid + 1;
            else
                r = mid - 1;
        }

        return false;
    }
};