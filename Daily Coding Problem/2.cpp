/*
 * Good morning! Here's your coding interview problem for today.
 * This problem was asked by Uber.
 * Given an array of integers, return a new array such that each element at index i of the new array is the product of all the numbers in the original array except the one at i.
 * For example, if our input was [1, 2, 3, 4, 5], the expected output would be [120, 60, 40, 30, 24]. If our input was [3, 2, 1], the expected output would be [2, 3, 6].
 * Follow-up: what if you can't use division?
 * 
 * Online Judge: https://leetcode.com/problems/product-of-array-except-self/
*/

class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        int tmp = 1;
        vector<int> res(nums.size(), 1);

        for (int i = 1; i < nums.size(); ++i)
            res[i] = res[i - 1] * nums[i - 1];

        for (int i = nums.size() - 2; i >= 0; --i)
        {
            tmp *= nums[i + 1];
            res[i] = res[i] * tmp;
        }

        return res;
    }
};