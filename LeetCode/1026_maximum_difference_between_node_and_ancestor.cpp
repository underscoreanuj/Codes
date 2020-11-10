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
    void maxAncestorDiffUtil(TreeNode *root, int &result, int min_so_far = INT_MAX, int max_so_far = INT_MIN)
    {
        if (!root)
            return;

        min_so_far = min(min_so_far, root->val);
        max_so_far = max(max_so_far, root->val);

        result = max(result, max_so_far - min_so_far);

        maxAncestorDiffUtil(root->left, result, min_so_far, max_so_far);
        maxAncestorDiffUtil(root->right, result, min_so_far, max_so_far);
    }

    int maxAncestorDiff(TreeNode *root)
    {
        int result = INT_MIN;
        maxAncestorDiffUtil(root, result);

        return result;
    }
};

auto speedup = []() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();