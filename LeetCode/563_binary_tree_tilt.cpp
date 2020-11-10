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
    int findTiltUtil(TreeNode *root, int &result)
    {
        if (!root)
            return 0;

        int l = findTiltUtil(root->left, result);
        int r = findTiltUtil(root->right, result);

        result += abs(l - r);

        return root->val + l + r;
    }

    int findTilt(TreeNode *root)
    {
        int result = 0;
        findTiltUtil(root, result);

        return result;
    }
};

auto speedup = []() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();