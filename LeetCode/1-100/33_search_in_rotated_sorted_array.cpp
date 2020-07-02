class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int l = 0, r = nums.size() - 1, mid = 0, val = 0;
        while (l <= r)
        {
            mid = l + ((r - l) >> 1);
            val = target < nums[0] ? (nums[mid] < nums[0] ? nums[mid] : -999999) : (nums[mid] < nums[0] ? 999999 : nums[mid]);

            if (val == target)
                return mid;
            else if (val < target)
                l = mid + 1;
            else
                r = mid - 1;
        }

        return -1;
    }
};