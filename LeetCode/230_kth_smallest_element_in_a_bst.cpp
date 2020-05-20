// time: O(n), space: O(n), iterative solution

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
    int kthSmallest(TreeNode *root, int k)
    {
        stack<TreeNode *> ST;
        TreeNode *cur = root;

        while (cur || !ST.empty())
        {
            while (cur)
            {
                ST.push(cur);
                cur = cur->left;
            }
            cur = ST.top();
            ST.pop();
            --k;
            if (k == 0)
                return cur->val;
            cur = cur->right;
        }

        return -1;
    }
};

auto speedup = []() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

// time: O(n), space: O(n), recursive solution

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
    void kthSmallestUtil(TreeNode *root, vector<int> &result)
    {
        if (!root)
            return;

        kthSmallestUtil(root->left, result);
        result.emplace_back(root->val);
        kthSmallestUtil(root->right, result);
    }

    int kthSmallest(TreeNode *root, int k)
    {
        vector<int> result;
        kthSmallestUtil(root, result);

        return result[k - 1];
    }
};

auto speedup = []() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();