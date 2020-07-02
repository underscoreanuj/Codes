/*
 *
 * Good morning! Here's your coding interview problem for today.
 * This problem was recently asked by Google.
 * Given a list of numbers and a number k, return whether any two numbers from the list add up to k.
 * For example, given [10, 15, 3, 7] and k of 17, return true since 10 + 7 is 17.
 * Bonus: Can you do this in one pass?
 * 
 * Online Judge: https://leetcode.com/problems/two-sum/
 *
*/

class Solution
{
public:
	vector<int> twoSum(vector<int> &nums, int target)
	{
		unordered_map<int, int> H;

		for (int i = 0; i < nums.size(); ++i)
		{
			if (H.find(target - nums[i]) != H.end())
				return {H[target - nums[i]], i};

			H.insert({nums[i], i});
		}

		return {0, 0};
	}
};