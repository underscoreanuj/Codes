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
    int diameterOfBinaryTreeUtil(TreeNode *root, int &diameter)
    {
        if (root == NULL)
            return 0;

        int left = diameterOfBinaryTreeUtil(root->left, diameter);
        int right = diameterOfBinaryTreeUtil(root->right, diameter);

        // update diameter with sum of left & right subtree heights if smaller
        diameter = max(diameter, left + right);

        // return the height of the current node
        return 1 + max(left, right);
    }

    int diameterOfBinaryTree(TreeNode *root)
    {
        int diameter = 0;
        diameterOfBinaryTreeUtil(root, diameter);

        return diameter;
    }
};