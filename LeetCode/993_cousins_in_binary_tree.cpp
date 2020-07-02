// dfs approach

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
    pair<TreeNode *, int> isCousinsUtil(TreeNode *root, TreeNode *parent, int val, int depth = 0)
    {
        if (!root)
            return {NULL, -1};
        if (root->val == val)
        {
            return {parent, depth};
        }
        auto l = isCousinsUtil(root->left, root, val, depth + 1);
        auto r = isCousinsUtil(root->right, root, val, depth + 1);

        if (l.second == -1)
            return r;
        return l;
    }

    bool isCousins(TreeNode *root, int x, int y)
    {
        auto x_info = isCousinsUtil(root, NULL, x);
        auto y_info = isCousinsUtil(root, NULL, y);

        return (x_info.first != y_info.first) && (x_info.second == y_info.second);
    }
};

// bfs approach

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
    bool isCousins(TreeNode *root, int x, int y)
    {
        if (!root || root->val == x || root->val == y)
            return false;

        queue<TreeNode *> Q;
        TreeNode *tmp;
        int cur_size = 0;
        Q.push(root);
        bool found_x = false, found_y = false;

        while (!Q.empty())
        {
            cur_size = Q.size();
            while (cur_size--)
            {
                tmp = Q.front();
                Q.pop();

                if (tmp->val == x)
                    found_x = true;
                if (tmp->val == y)
                    found_y = true;

                if (tmp->left && tmp->right)
                {
                    if ((tmp->left->val == x && tmp->right->val == y) || tmp->left->val == y && tmp->right->val == x)
                        return false;
                }

                if (tmp->left)
                    Q.push(tmp->left);
                if (tmp->right)
                    Q.push(tmp->right);
            }

            if (found_x ^ found_y)
                return false;
            if (found_x && found_y)
                return true;
        }

        return false;
    }
};