//recursive solution without stack O(n)

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
    int idx = 0;
    TreeNode *bstFromPreorder(vector<int> &preorder, int limit = INT_MAX)
    {
        if (idx >= preorder.size() || preorder[idx] >= limit)
            return NULL;

        TreeNode *root = new TreeNode(preorder[idx++]);
        root->left = bstFromPreorder(preorder, root->val);
        root->right = bstFromPreorder(preorder, limit);

        return root;
    }
};

// recursive solution without stack O(n^2)

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
    TreeNode *bstFromPreorderUtil(vector<int> &preorder, int l, int r)
    {
        if (l == r)
            return new TreeNode(preorder[l]);
        if (l > r)
            return NULL;

        int mid = l;
        for (int i = l + 1; i <= r; ++i)
        {
            if (preorder[i] > preorder[l])
                break;
            ++mid;
        }

        TreeNode *root = new TreeNode(preorder[l]);
        root->left = bstFromPreorderUtil(preorder, l + 1, mid);
        root->right = bstFromPreorderUtil(preorder, mid + 1, r);

        return root;
    }

    TreeNode *bstFromPreorder(vector<int> &preorder)
    {
        if (preorder.size() == 0)
            return NULL;

        TreeNode *root = bstFromPreorderUtil(preorder, 0, preorder.size() - 1);

        return root;
    }
};

// stack solution

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
    TreeNode *bstFromPreorder(vector<int> &preorder)
    {
        if (preorder.size() == 0)
            return NULL;

        stack<TreeNode *> S;
        TreeNode *root = new TreeNode(preorder[0]);
        S.push(root);

        for (int i = 1; i < preorder.size(); ++i)
        {
            TreeNode *tmp = new TreeNode(preorder[i]);
            if (S.top()->val > preorder[i])
            {
                S.top()->left = tmp;
            }
            else
            {
                TreeNode *cur = S.top();
                S.pop();
                while (!S.empty() && S.top()->val < preorder[i])
                {
                    cur = S.top();
                    S.pop();
                }
                cur->right = tmp;
            }
            S.push(tmp);
        }

        return root;
    }
};