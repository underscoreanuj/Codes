// iterative solution

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
    vector<int> postorderTraversal(TreeNode *root)
    {
        vector<int> result;
        stack<TreeNode *> S;

        TreeNode *cur = root;
        TreeNode *last = NULL;

        while (S.size() || cur)
        {
            while (cur)
            {
                S.push(cur);
                cur = cur->left;
            }
            cur = S.top();
            if (cur->right && last != cur->right)
            {
                cur = cur->right;
            }
            else
            {
                result.emplace_back(cur->val);
                S.pop();
                last = cur;
                cur = NULL;
            }
        }

        return result;
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
    void postorderTraversalUtil(TreeNode *root, vector<int> &result)
    {
        if (!root)
            return;

        postorderTraversalUtil(root->left, result);
        postorderTraversalUtil(root->right, result);
        result.emplace_back(root->val);
    }

    vector<int> postorderTraversal(TreeNode *root)
    {
        vector<int> result;
        postorderTraversalUtil(root, result);

        return result;
    }
};

auto speedup = []() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();