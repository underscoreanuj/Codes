class Solution
{
public:
    int bound_search(vector<int> &nums, int target, bool upper = false)
    {
        int l = 0, r = nums.size() - 1, mid = 0;
        while (l <= r)
        {
            mid = l + ((r - l) >> 1);
            if (nums[mid] == target)
            {
                if (!upper)
                {
                    if (mid == 0 || nums[mid - 1] != target)
                        return mid;
                    else
                        r = mid - 1;
                }
                else
                {
                    if (mid == nums.size() - 1 || nums[mid + 1] != target)
                        return mid;
                    else
                        l = mid + 1;
                }
            }
            else if (nums[mid] < target)
                l = mid + 1;
            else
                r = mid - 1;
        }

        return -1;
    }

    vector<int> searchRange(vector<int> &nums, int target)
    {
        if (nums.size() == 0)
            return {-1, -1};

        int lower = bound_search(nums, target);
        int upper = bound_search(nums, target, true);

        return {lower, upper};
    }
};