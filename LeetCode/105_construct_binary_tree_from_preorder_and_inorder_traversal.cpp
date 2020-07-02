// efficient solution with hashing

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
    TreeNode *buildTreeUtil(vector<int> &preorder, vector<int> &inorder, int &idx, int l, int r, unordered_map<int, int> &mem)
    {
        if (l > r)
            return NULL;

        int i = mem[preorder[idx]];

        TreeNode *root = new TreeNode(preorder[idx++]);

        root->left = buildTreeUtil(preorder, inorder, idx, l, i - 1, mem);
        root->right = buildTreeUtil(preorder, inorder, idx, i + 1, r, mem);

        return root;
    }

    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        unordered_map<int, int> mem;
        for (int i = 0; i < inorder.size(); ++i)
            mem[inorder[i]] = i;
        int idx = 0;

        return buildTreeUtil(preorder, inorder, idx, 0, preorder.size() - 1, mem);
    }
};

auto speedup = []() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

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