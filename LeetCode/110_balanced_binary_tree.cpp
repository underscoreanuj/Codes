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
    int getHeight(TreeNode *root)
    {
        if (!root)
            return 0;

        int l_height = getHeight(root->left);
        if (l_height == -1)
            return -1;
        int r_height = getHeight(root->right);
        if (r_height == -1)
            return -1;

        if (abs(l_height - r_height) > 1)
            return -1;

        return 1 + max(l_height, r_height);
    }

    bool isBalanced(TreeNode *root)
    {
        return getHeight(root) != -1;
    }
};

auto speedup = []() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();