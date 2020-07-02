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
    bool isSymmetric(TreeNode *root)
    {
        if (!root)
            return true;
        stack<pair<TreeNode *, TreeNode *>> S;
        pair<TreeNode *, TreeNode *> cur;
        S.push({root->left, root->right});

        while (!S.empty())
        {
            cur = S.top();
            S.pop();
            if (cur.first && cur.second)
            {
                if (cur.first->val != cur.second->val)
                    return false;
                S.push({cur.first->left, cur.second->right});
                S.push({cur.first->right, cur.second->left});
            }
            else if ((!cur.first && cur.second) || (cur.first && !cur.second))
                return false;
        }

        return true;
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
    bool isSymmetricUtil(TreeNode *root1, TreeNode *root2)
    {
        if (!root1 && !root2)
            return true;
        if (root1 && root2)
        {
            if (root1->val != root2->val)
                return false;
            else
                return isSymmetricUtil(root1->left, root2->right) && isSymmetricUtil(root1->right, root2->left);
        }
        else
            return false;
    }

    bool isSymmetric(TreeNode *root)
    {
        if (!root)
            return true;
        return isSymmetricUtil(root->left, root->right);
    }
};