/**
 * Good morning! Here's your coding interview problem for today.
 * This problem was asked by Amazon.
 * An sorted array of integers was rotated an unknown number of times.
 * Given such an array, find the index of the element in the array in faster than linear time. If the element doesn't exist in the array, return null.
 * For example, given the array [13, 18, 25, 2, 8, 10] and the element 8, return 4 (the index of 8 in the array).
 * You can assume all the integers in the array are unique.
 * 
 * 
 * 
 * Online Judge: https://leetcode.com/problems/search-in-rotated-sorted-array/
 * 
 */

class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int l = 0, r = nums.size() - 1, mid = 0, val = 0;

        while (l <= r)
        {
            mid = l + ((r - l) >> 1);

            val = (target < nums[0] ? nums[mid] < nums[0] ? nums[mid] : INT_MIN : nums[mid] < nums[0] ? INT_MAX : nums[mid]);

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

auto speedup = []() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();