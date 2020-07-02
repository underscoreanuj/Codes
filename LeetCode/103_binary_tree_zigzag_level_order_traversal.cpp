// normal bfs + reverse solution

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
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        if (!root)
            return {};

        vector<vector<int>> result;
        queue<TreeNode *> Q;
        Q.push(root);

        TreeNode *cur = NULL;
        int q_size = 0;

        while (!Q.empty())
        {
            q_size = Q.size();
            vector<int> res;
            while (q_size--)
            {
                cur = Q.front();
                Q.pop();

                res.emplace_back(cur->val);
                if (cur->left)
                    Q.push(cur->left);
                if (cur->right)
                    Q.push(cur->right);
            }

            result.emplace_back(res);
        }

        for (int i = 1; i < result.size(); i += 2)
            reverse(result[i].begin(), result[i].end());

        return result;
    }
};
