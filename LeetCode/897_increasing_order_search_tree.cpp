// in place linking

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
    TreeNode *head = NULL;
    TreeNode *prev = NULL;

    void increasingBSTUtil(TreeNode *root)
    {
        if (!root)
            return;

        increasingBSTUtil(root->left);

        if (!head)
            head = root;
        if (prev)
        {
            root->left = NULL;
            prev->right = root;
        }
        prev = root;

        increasingBSTUtil(root->right);
    }

    TreeNode *increasingBST(TreeNode *root)
    {
        increasingBSTUtil(root);

        return head;
    }
};

auto speedup = []() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();