/**
 * Good morning! Here's your coding interview problem for today.
 * This problem was asked by Facebook.
 * Given a list of integers, return the largest product that can be made by multiplying any three integers.
 * For example, if the list is [-10, -10, 5, 2], we should return 500, since that's -10 * -10 * 5.
 * You can assume the list has at least three integers.
 * 
 * 
 * Online Judge: https://leetcode.com/problems/maximum-product-of-three-numbers/
 * 
 */

// O(N) solution

class Solution
{
public:
    int maximumProduct(vector<int> &nums)
    {
        int min1 = INT_MAX, min2 = INT_MAX, max1 = INT_MIN, max2 = INT_MIN, max3 = INT_MIN;

        for (int &n : nums)
        {
            if (n < min1)
            {
                min2 = min1;
                min1 = n;
            }
            else if (n < min2)
                min2 = n;

            if (n > max1)
            {
                max3 = max2;
                max2 = max1;
                max1 = n;
            }
            else if (n > max2)
            {
                max3 = max2;
                max2 = n;
            }
            else if (n > max3)
                max3 = n;
        }

        return max(min1 * min2 * max1, max1 * max2 * max3);
    }
};

auto speedup = []() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

// O(NlogN) sorting solution

class Solution
{
public:
    int maximumProduct(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        return max(nums[0] * nums[1] * nums[n - 1], nums[n - 1] * nums[n - 2] * nums[n - 3]);
    }
};

auto speedup = []() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();