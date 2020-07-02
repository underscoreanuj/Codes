/**
 * Good morning! Here's your coding interview problem for today.
 * This problem was asked by Google.
 * The power set of a set is the set of all its subsets. Write a function that, given a set, generates its power set.
 * For example, given the set {1, 2, 3}, it should return {{}, {1}, {2}, {3}, {1, 2}, {1, 3}, {2, 3}, {1, 2, 3}}.
 * You may also use a list or array to represent a set.
 * 
 * 
 * Online Judge: https://leetcode.com/problems/subsets/
 * 
 */

class Solution
{
public:
    vector<vector<int>> subsets(vector<int> &nums)
    {
        vector<vector<int>> result;
        int limit = 1 << nums.size();
        cout << limit;
        for (int i = 0; i < limit; ++i)
        {
            vector<int> res;
            for (int j = 0; j < nums.size(); ++j)
            {
                if (i & (1 << j))
                    res.emplace_back(nums[j]);
            }
            result.emplace_back(res);
        }

        return result;
    }
};

auto speedup = []() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();