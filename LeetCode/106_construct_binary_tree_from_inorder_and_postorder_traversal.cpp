// efficient solution using hashing

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
    TreeNode *buildTreeUtil(vector<int> &inorder, vector<int> &postorder, int &idx, int l, int r, unordered_map<int, int> &mem)
    {
        if (l > r)
            return NULL;

        int i = mem[postorder[idx]];

        TreeNode *root = new TreeNode(postorder[idx--]);

        root->right = buildTreeUtil(inorder, postorder, idx, i + 1, r, mem);
        root->left = buildTreeUtil(inorder, postorder, idx, l, i - 1, mem);

        return root;
    }

    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
    {
        unordered_map<int, int> mem;
        for (int i = 0; i < inorder.size(); ++i)
            mem[inorder[i]] = i;
        int idx = postorder.size() - 1;

        return buildTreeUtil(inorder, postorder, idx, 0, postorder.size() - 1, mem);
    }
};

auto speedup = []() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

// recursive solution

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
    TreeNode *buildTreeUtil(vector<int> &inorder, vector<int> &postorder, int &idx, int l, int r)
    {
        if (l > r)
            return NULL;

        int i = l;
        for (; i <= r; ++i)
            if (inorder[i] == postorder[idx])
                break;

        TreeNode *root = new TreeNode(postorder[idx--]);

        root->right = buildTreeUtil(inorder, postorder, idx, i + 1, r);
        root->left = buildTreeUtil(inorder, postorder, idx, l, i - 1);

        return root;
    }

    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
    {
        int idx = postorder.size() - 1;

        return buildTreeUtil(inorder, postorder, idx, 0, postorder.size() - 1);
    }
};