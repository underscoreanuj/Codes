// iterative solution (constant space) [Morris Traversal]   (note that we do in inorder traversal instead of preorder, and have changed the calulation process accordingly -> technically any dfs approach can be used)

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
    int sumRootToLeaf(TreeNode *root)
    {
        TreeNode *cur = root;
        TreeNode *tmp = NULL;

        int result = 0, num = 0, count = 0;

        while (cur)
        {
            if (cur->left)
            {
                tmp = cur->left;

                count = 1;
                while (tmp->right && tmp->right != cur)
                {
                    tmp = tmp->right;
                    ++count;
                }

                if (tmp->right == NULL)
                {
                    num = (num << 1) | cur->val;
                    tmp->right = cur;
                    cur = cur->left;
                }
                else
                {
                    if (tmp->left == NULL)
                        result += num;
                    num >>= count;

                    tmp->right = NULL;
                    cur = cur->right;
                }
            }
            else
            {
                num = (num << 1) | cur->val;
                if (cur->right == NULL)
                {
                    result += num;
                }

                cur = cur->right;
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
    int sumRootToLeaf(TreeNode *root)
    {
        stack<pair<TreeNode *, int>> S;
        TreeNode *cur = root;

        int result = 0, num = 0;

        while (cur || S.size())
        {
            while (cur)
            {
                num = ((num << 1) | cur->val);
                S.push({cur, num});
                cur = cur->left;
            }

            tie(cur, num) = S.top();
            S.pop();
            if (!cur->left && !cur->right)
                result += num;
            cur = cur->right;
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
    void sumRootToLeafUtil(TreeNode *root, int num, int &result)
    {
        if (root)
        {
            num = ((num << 1) | root->val);

            if (!root->left && !root->right)
            {
                result += num;
                return;
            }

            sumRootToLeafUtil(root->left, num, result);
            sumRootToLeafUtil(root->right, num, result);
        }
    }

    int sumRootToLeaf(TreeNode *root)
    {
        int result = 0;

        sumRootToLeafUtil(root, 0, result);

        return result;
    }
};

auto speedup = []() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();
