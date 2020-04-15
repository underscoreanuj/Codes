/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution
{
public:
    int result;

    int longestUnivaluePathUtil(TreeNode *root)
    {
        if (!root || (!root->left && !root->right))
            return 0;

        int left = longestUnivaluePathUtil(root->left);
        int right = longestUnivaluePathUtil(root->right);

        int res = 0;

        if (root->left && root->left->val == root->val)
            res += ++left;
        else
            left = 0;
        if (root->right && root->right->val == root->val)
            res += ++right;
        else
            right = 0;

        result = max(result, res);

        return max(left, right);
    }

    int longestUnivaluePath(TreeNode *root)
    {
        result = 0;
        longestUnivaluePathUtil(root);

        return result;
    }
};

auto speedup = []() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();