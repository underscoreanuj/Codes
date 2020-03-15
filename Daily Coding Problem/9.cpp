/*
 *
 * Good morning! Here's your coding interview problem for today. 
 * This problem was asked by Airbnb.
 * Given a list of integers, write a function that returns the largest sum of non-adjacent numbers. Numbers can be 0 or negative.
 * For example, [2, 4, 6, 2, 5] should return 13, since we pick 2, 6, and 5. [5, 1, 1, 5] should return 10, since we pick 5 and 5.
 * Follow-up: Can you do this in O(N) time and constant space?
 * 
 * 
 * Online Judge: https://leetcode.com/problems/house-robber/
 * 
*/

class Solution
{
public:
    int rob(vector<int> &nums)
    {
        if (nums.size() == 0)
            return 0;
        if (nums.size() == 1)
            return nums[0];
        if (nums.size() == 2)
            return max(nums[0], nums[1]);

        int incl = nums[0], excl = 0, tmp = 0;

        for (int i = 1; i < nums.size(); ++i)
        {
            tmp = incl;
            incl = max(incl, nums[i] + excl);
            excl = tmp;
        }

        return max(incl, excl);
    }
};