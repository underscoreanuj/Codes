// class Solution
// {
// public:
//     vector<int> productExceptSelf(vector<int> &nums)
//     {
//         vector<int> prefixProduct(nums.size(), 1);
//         vector<int> suffixProduct(nums.size(), 1);
//         vector<int> res(nums.size(), 0);

//         for (int i = 1; i < nums.size(); ++i)
//         {
//             prefixProduct[i] = prefixProduct[i - 1] * nums[i - 1];
//         }

//         for (int i = nums.size() - 2; i >= 0; --i)
//         {
//             suffixProduct[i] = suffixProduct[i + 1] * nums[i + 1];
//         }

//         for (int i = 0; i < nums.size(); ++i)
//         {
//             res[i] = prefixProduct[i] * suffixProduct[i];
//         }

//         return res;
//     }
// };

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