// iterative solution

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
    vector<int> preorderTraversal(TreeNode *root)
    {
        vector<int> result;
        stack<TreeNode *> S;
        TreeNode *cur = root;

        while (cur || !S.empty())
        {
            while (cur)
            {
                result.push_back(cur->val);
                S.push(cur);
                cur = cur->left;
            }
            cur = S.top();
            S.pop();
            cur = cur->right;
        }

        return result;
    }
};

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
    vector<int> preorderTraversal(TreeNode *root)
    {
        vector<int> result;
        stack<TreeNode *> S;
        TreeNode *cur = root;

        while (cur || !S.empty())
        {
            result.push_back(cur->val);
            if (cur->right)
                S.push(cur->right);
            if (cur->left)
                cur = cur->left;
            else if (!S.empty())
            {
                cur = S.top();
                S.pop();
            }
            else
                break;
        }

        return result;
    }
};

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
    vector<int> result;

    void preorderTraversalUtil(TreeNode *root)
    {
        if (root)
        {
            result.push_back(root->val);
            preorderTraversalUtil(root->left);
            preorderTraversalUtil(root->right);
        }
    }

    vector<int> preorderTraversal(TreeNode *root)
    {
        preorderTraversalUtil(root);
        return result;
    }
};