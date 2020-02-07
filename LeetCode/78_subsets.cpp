// class Solution {
// public:
//     vector<vector<int>> subsets(vector<int>& nums) {
//         if(nums.size() == 0) return {{}};
//         vector<vector<int>> ret = {{}};
//         vector<int> sol;
//         int sz = 0;

//         for(int n : nums) {
//             sz = ret.size();
//             for(int i=0; i<sz; ++i) {
//                 sol.clear();
//                 sol = ret[i];
//                 sol.emplace_back(n);
//                 ret.emplace_back(sol);
//             }
//         }

//         return ret;
//     }
// };

class Solution
{
public:
    vector<vector<int>> subsets(vector<int> &nums)
    {
        if (nums.size() == 0)
            return {{}};
        vector<vector<int>> ret;
        vector<int> sol;
        int count = 1 << nums.size();

        for (int i = 0; i < count; ++i)
        {
            sol.clear();
            for (int j = 0; j < nums.size(); ++j)
            {
                if (i & (1 << j))
                    sol.emplace_back(nums[j]);
            }
            ret.emplace_back(sol);
        }

        return ret;
    }
};