/* 
 *
 * Good morning! Here's your coding interview problem for today.
 * This problem was asked by Stripe.
 * Given an array of integers, find the first missing positive integer in linear time and constant space. In other words, find the lowest positive integer that does not exist in the array. The array can contain duplicates and negative numbers as well.
 * For example, the input [3, 4, -1, 1] should give 2. The input [1, 2, 0] should give 3.
 * You can modify the input array in-place.
 * 
 * 
 * Online Judge: https://leetcode.com/problems/first-missing-positive/
 * 
*/

class Solution
{
public:
    int firstMissingPositive(vector<int> &nums)
    {
        int j = 0, i = 0, val = 0;
        for (i = 0; i < nums.size(); ++i)
            if (nums[i] > 0)
                swap(nums[i], nums[j++]);

        for (i = 0; i < j; ++i)
        {
            val = abs(nums[i]) - 1;
            if (val < j && nums[val] > 0)
                nums[val] = -nums[val];
        }

        for (i = 0; i < j; ++i)
            if (nums[i] > 0)
                return i + 1;

        return j + 1;
    }
};