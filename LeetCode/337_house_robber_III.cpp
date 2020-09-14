// efficient soution (same linear time complexity)

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
    pair<int, int> robUtil(TreeNode *root)
    {
        if (!root)
            return {0, 0};

        pair<int, int> l = robUtil(root->left);
        pair<int, int> r = robUtil(root->right);

        int excl = max(l.first, l.second) + max(r.first, r.second);
        int incl = root->val + l.first + r.first;

        return {excl, incl};
    }

    int rob(TreeNode *root)
    {
        pair<int, int> res = robUtil(root);

        return max(res.first, res.second);
    }
};

auto speedup = []() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

// simple solution with recursive memoization

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
    unordered_map<TreeNode *, int> mem;

    int rob(TreeNode *root)
    {
        if (!root)
            return 0;
        if (mem.count(root))
            return mem[root];

        int res = root->val;

        if (root->left)
            res += rob(root->left->left) + rob(root->left->right);

        if (root->right)
            res += rob(root->right->left) + rob(root->right->right);

        mem[root] = max(res, rob(root->left) + rob(root->right));

        return mem[root];
    }
};

auto speedup = []() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();