// normal recursive solution

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
    int idx = 0;

public:
    TreeNode *buildTreeUtil(vector<int> &preorder, vector<int> &inorder, int l, int r)
    {
        if (l > r)
            return NULL;

        int i = l;
        for (; i <= r; ++i)
            if (preorder[idx] == inorder[i])
                break;

        TreeNode *root = new TreeNode(preorder[idx++]);

        root->left = buildTreeUtil(preorder, inorder, l, i - 1);
        root->right = buildTreeUtil(preorder, inorder, i + 1, r);

        return root;
    }

    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        return buildTreeUtil(preorder, inorder, 0, preorder.size() - 1);
    }
};