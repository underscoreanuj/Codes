// divide and conquer

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    TreeNode *sortedArrayToBSTUtil(vector<int> &nums, int l, int r)
    {
        if (l <= r)
        {
            int mid = l + ((r - l) >> 1);

            TreeNode *root = new TreeNode(nums[mid]);
            root->left = sortedArrayToBSTUtil(nums, l, mid - 1);
            root->right = sortedArrayToBSTUtil(nums, mid + 1, r);

            return root;
        }
        else
            return NULL;
    }

    TreeNode *sortedArrayToBST(vector<int> &nums)
    {
        return sortedArrayToBSTUtil(nums, 0, nums.size() - 1);
    }
};

auto speedup = []() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();