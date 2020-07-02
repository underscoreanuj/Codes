// iterative solution (using queue)

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
    TreeNode *invertTree(TreeNode *root)
    {
        if (!root)
            return NULL;

        TreeNode *cur = NULL;
        TreeNode *tmp = NULL;
        queue<TreeNode *> Q;
        Q.push(root);

        while (!Q.empty())
        {
            cur = Q.front();
            Q.pop();

            tmp = cur->left;
            cur->left = cur->right;
            cur->right = tmp;

            if (cur->left)
                Q.push(cur->left);
            if (cur->right)
                Q.push(cur->right);
        }

        return root;
    }
};

auto speedup = []() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

// iterative solution (using stack)

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
    TreeNode *invertTree(TreeNode *root)
    {
        if (!root)
            return NULL;

        TreeNode *cur = root;
        TreeNode *tmp = NULL;
        stack<TreeNode *> S;

        while (cur || !S.empty())
        {
            while (cur)
            {
                if (cur->right)
                    S.push(cur->right);

                tmp = cur->right;
                cur->right = cur->left;
                cur->left = tmp;

                cur = cur->right;
            }
            if (S.size())
            {
                cur = S.top();
                S.pop();
            }
        }

        return root;
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
    TreeNode *invertTree(TreeNode *root)
    {
        if (!root)
            return NULL;

        TreeNode *left = invertTree(root->left);
        TreeNode *right = invertTree(root->right);
        root->left = right;
        root->right = left;

        return root;
    }
};

auto speedup = []() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();