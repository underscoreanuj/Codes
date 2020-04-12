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
    vector<vector<int>> result;

    void pathSumUtil(TreeNode *root, int sum, vector<int> &res)
    {
        if (root == NULL)
            return;

        res.push_back(root->val);
        if (root->left == NULL && root->right == NULL && root->val == sum)
        {
            result.emplace_back(res);
        }

        pathSumUtil(root->left, sum - root->val, res);
        pathSumUtil(root->right, sum - root->val, res);

        res.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode *root, int sum)
    {
        vector<int> res;
        pathSumUtil(root, sum, res);

        return result;
    }
};