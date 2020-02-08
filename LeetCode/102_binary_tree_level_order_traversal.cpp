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
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        if (root == NULL)
        {
            {
            }
        };

        vector<vector<int>> ret;
        vector<int> sol;
        queue<TreeNode *> Q;
        Q.push(root);
        TreeNode *tmp = NULL;
        int sz = 0;

        while (!Q.empty())
        {
            sz = Q.size();
            sol.clear();
            while (sz--)
            {
                tmp = Q.front();
                Q.pop();
                if (tmp == NULL)
                    return {};
                sol.emplace_back(tmp->val);
                if (tmp->left)
                    Q.push(tmp->left);
                if (tmp->right)
                    Q.push(tmp->right);
            }
            ret.emplace_back(sol);
        }

        return ret;
    }
};