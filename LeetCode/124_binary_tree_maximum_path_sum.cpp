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
    int maxPathSumUtil(TreeNode *root, int &result)
    {
        if (root == NULL)
            return 0;

        int left = max(0, maxPathSumUtil(root->left, result));
        int right = max(0, maxPathSumUtil(root->right, result));

        result = max(result, root->val + left + right);

        return root->val + max(left, right);
    }

    int maxPathSum(TreeNode *root)
    {
        int result = INT_MIN;
        maxPathSumUtil(root, result);

        return result;
    }
};