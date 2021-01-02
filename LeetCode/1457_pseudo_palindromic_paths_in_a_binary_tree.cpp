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
    void pseudoPalindromicPathsUtil(TreeNode *root, int &result, int path = 0)
    {
        if (!root)
            return;
        path ^= (1 << root->val);

        if (!root->left && !root->right)
            if ((path & (path - 1)) == 0)
                ++result;

        pseudoPalindromicPathsUtil(root->left, result, path);
        pseudoPalindromicPathsUtil(root->right, result, path);
    }

    int pseudoPalindromicPaths(TreeNode *root)
    {
        int result = 0;
        pseudoPalindromicPathsUtil(root, result);

        return result;
    }
};

auto speedup = []() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();