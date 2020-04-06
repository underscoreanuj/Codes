/*
 *
 * Good morning! Here's your coding interview problem for today.
 * This problem was asked by Google.
 * Given an array of integers and a number k, where 1 <= k <= length of the array, compute the maximum values of each subarray of length k.
 * For example, given array = [10, 5, 2, 7, 8, 7] and k = 3, we should get: [10, 7, 8, 8], since:

    10 = max(10, 5, 2)
    7 = max(5, 2, 7)
    8 = max(2, 7, 8)
    8 = max(7, 8, 7)

 * Do this in O(n) time and O(k) space. You can modify the input array in-place and you do not need to store the results. You can simply print them out as you compute them.
 * 
*/

class Solution
{
public:
   vector<int> maxSlidingWindow(vector<int> &nums, int k)
   {
      vector<int> result;
      deque<int> window;

      for (int i = 0; i < nums.size(); ++i)
      {
         while (!window.empty() && nums[i] >= nums[window.back()])
            window.pop_back();
         window.emplace_back(i);
         if (i >= k - 1)
            result.emplace_back(nums[window.front()]);
         while (!window.empty() && window.front() <= i - k + 1)
            window.pop_front();
      }

      return result;
   }
};