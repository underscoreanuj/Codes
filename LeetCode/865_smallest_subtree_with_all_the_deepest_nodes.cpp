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
    pair<TreeNode *, int> subtreeWithAllDeepestUtil(TreeNode *root)
    {
        if (!root)
            return {NULL, 0};

        pair<TreeNode *, int> l = subtreeWithAllDeepestUtil(root->left);
        pair<TreeNode *, int> r = subtreeWithAllDeepestUtil(root->right);

        return {(l.second == r.second ? root : l.second > r.second ? l.first : r.first), 1 + max(l.second, r.second)};
    }

    TreeNode *subtreeWithAllDeepest(TreeNode *root)
    {
        return subtreeWithAllDeepestUtil(root).first;
    }
};

auto speedup = []() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();