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

// iterative solution - without stack - Morris Traversal

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