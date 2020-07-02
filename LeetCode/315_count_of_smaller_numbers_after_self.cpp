// O(n^2) approach besides the naive approach which uses two loops
// ***********  Gives TLE  [probably use indexed set, to get O(nlogn)]

class Solution
{
public:
    vector<int> countSmaller(vector<int> &nums)
    {
        vector<int> result(nums.size(), 0);
        multiset<int> tab;

        for (int i = nums.size() - 1; i >= 0; --i)
        {
            result[i] = distance(tab.begin(), tab.lower_bound(nums[i]));
            tab.insert(nums[i]);
        }

        return result;
    }
};