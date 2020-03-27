// iterative solution

// recursive solution

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
    vector<int> ret;

    void inorderTraversalUtil(TreeNode *root)
    {
        if (!root)
            return;
        inorderTraversalUtil(root->left);
        ret.push_back(root->val);
        inorderTraversalUtil(root->right);
    }

    vector<int> inorderTraversal(TreeNode *root)
    {
        inorderTraversalUtil(root);
        return ret;
    }
};