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
    bool isValidBST(TreeNode *root, long long int left = LONG_MIN, long long int right = LONG_MAX)
    {
        if (root == NULL)
            return true;

        if (left < root->val && root->val < right)
            return (isValidBST(root->left, left, root->val) && isValidBST(root->right, root->val, right));
        else
            return false;
    }
};