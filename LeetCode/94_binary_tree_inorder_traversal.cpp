// iterative solution - without stack - Morris Traversal  (Tree is not modified)

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
    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<int> result;

        TreeNode *cur = root;
        TreeNode *tmp = NULL;

        while (cur)
        {
            if (cur->left)
            {
                tmp = cur->left;
                while (tmp->right && tmp->right != cur)
                    tmp = tmp->right;

                if (tmp->right)
                {
                    tmp->right = NULL;
                    result.emplace_back(cur->val);
                    cur = cur->right;
                }
                else
                {
                    tmp->right = cur;
                    cur = cur->left;
                }
            }
            else
            {
                result.emplace_back(cur->val);
                cur = cur->right;
            }
        }

        return result;
    }
};

// iterative solution - without stack - Morris Traversal  (modifies tree)

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
    vector<int> inorderTraversal(TreeNode *root)
    {
        if (!root)
            return {};

        vector<int> result;
        TreeNode *cur = root;
        TreeNode *tmp = NULL;

        while (cur)
        {
            if (cur->left)
            {
                tmp = cur->left;
                while (tmp->right)
                    tmp = tmp->right;
                tmp->right = cur;
                tmp = cur;
                cur = cur->left;
                tmp->left = NULL;
            }
            else
            {
                result.push_back(cur->val);
                cur = cur->right;
            }
        }

        return result;
    }
};

// iterative solution - using stack

class Solution
{
public:
    vector<int> inorderTraversal(TreeNode *root)
    {
        if (!root)
            return {};

        vector<int> result;
        stack<TreeNode *> S;
        TreeNode *cur = root;

        while (cur || !S.empty())
        {
            while (cur)
            {
                S.push(cur);
                cur = cur->left;
            }
            cur = S.top();
            S.pop();
            result.push_back(cur->val);
            cur = cur->right;
        }

        return result;
    }
};

// recursive solution

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