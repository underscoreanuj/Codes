/**
 * Good morning! Here's your coding interview problem for today.
 * This problem was asked by Google.
 * Given an array of strictly the characters 'R', 'G', and 'B', segregate the values of the array so that all the Rs come first, the Gs come second, and the Bs come last. You can only swap elements of the array.
 * Do this in linear time and in-place.
 * For example, given the array ['G', 'B', 'R', 'R', 'B', 'R', 'G'], it should become ['R', 'R', 'R', 'G', 'G', 'B', 'B'].
 * 
 * 
 * 
 * Online Judge: https://leetcode.com/problems/sort-colors/
 * 
 * 
 */

// consider 0 = R, 1 = G, 2 = B

class Solution
{
public:
    void sortColors(vector<int> &nums)
    {
        int idx_1 = 0, idx_2 = nums.size() - 1;

        for (int i = 0; i < nums.size(); ++i)
        {
            if (nums[i] == 0 && i > idx_1)
                swap(nums[i--], nums[idx_1++]);
            if (nums[i] == 2 && i < idx_2)
                swap(nums[i--], nums[idx_2--]);
        }
    }
};