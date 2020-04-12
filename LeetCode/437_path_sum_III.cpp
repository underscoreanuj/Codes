
// O(n) solution



// O(n^2) solution

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
    void pathSumUtil(TreeNode *root, int sum)
    {
        if (root == NULL)
            return;
        if (root->val == sum)
            ++result;
        pathSumUtil(root->left, sum - root->val);
        pathSumUtil(root->right, sum - root->val);
    }

    void traverse(TreeNode *root, int &sum)
    {
        if (root)
        {
            traverse(root->left, sum);
            pathSumUtil(root, sum);
            traverse(root->right, sum);
        }
    }

    int pathSum(TreeNode *root, int sum)
    {
        result = 0;
        traverse(root, sum);
        return result;
    }
};