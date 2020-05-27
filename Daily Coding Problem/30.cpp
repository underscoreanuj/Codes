/**
 * 
 * Good morning! Here's your coding interview problem for today.
 * This problem was asked by Facebook.
 * You are given an array of non-negative integers that represents a two-dimensional elevation map where each element is unit-width wall and the integer is the height. Suppose it will rain and all spots between two walls get filled up.
 * Compute how many units of water remain trapped on the map in O(N) time and O(1) space.
 * For example, given the input [2, 1, 2], we can hold 1 unit of water in the middle.
 * Given the input [3, 0, 1, 3, 0, 5], we can hold 3 units in the first index, 2 in the second, and 3 in the fourth index (we cannot hold 5 since it would run off to the left), so we can trap 8 units of water.
 *
 * 
 * 
 * Online Judge: https://leetcode.com/problems/trapping-rain-water/
 * 
 */

class Solution
{
public:
    int trap(vector<int> &height)
    {
        if (height.size() < 3)
            return 0;

        int result = 0;
        int max_left = INT_MIN, max_right = INT_MIN;
        int l = 0, r = height.size() - 1;

        while (l < r)
        {
            max_left = max(max_left, height[l]);
            max_right = max(max_right, height[r]);

            if (height[l] < max_left)
                result += (max_left - height[l]);
            if (height[r] < max_right)
                result += (max_right - height[r]);

            if (max_left <= max_right)
                ++l;
            else
                --r;
        }

        return result;
    }
};