// constant space solution (Morris Traversal)

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
    void recoverTree(TreeNode *root)
    {
        TreeNode *cur = root;
        TreeNode *tmp = NULL;

        TreeNode *first = NULL;
        TreeNode *second = NULL;
        TreeNode *prev = new TreeNode(INT_MIN);

        while (cur)
        {
            if (cur->left)
            {
                tmp = cur->left;
                while (tmp->right && tmp->right != cur)
                    tmp = tmp->right;

                if (tmp->right)
                {
                    tmp->right = NULL;
                    if (!first && cur->val < prev->val)
                        first = prev;
                    if (first && cur->val < prev->val)
                        second = cur;
                    prev = cur;
                    cur = cur->right;
                }
                else
                {
                    tmp->right = cur;
                    cur = cur->left;
                }
            }
            else
            {
                if (!first && cur->val < prev->val)
                    first = prev;
                if (first && cur->val < prev->val)
                    second = cur;
                prev = cur;
                cur = cur->right;
            }
        }

        int t = first->val;
        first->val = second->val;
        second->val = t;
    }
};

auto speedup = []() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

// solution with stack

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
    void recoverTree(TreeNode *root)
    {
        TreeNode *first = NULL;
        TreeNode *second = NULL;
        TreeNode *prev = new TreeNode(INT_MIN);

        stack<TreeNode *> S;
        TreeNode *cur = root;

        while (!S.empty() || cur)
        {
            while (cur)
            {
                S.push(cur);
                cur = cur->left;
            }
            cur = S.top();
            S.pop();

            if (!first && cur->val < prev->val)
                first = prev;
            if (first && cur->val < prev->val)
                second = cur;
            prev = cur;

            cur = cur->right;
        }

        int tmp = first->val;
        first->val = second->val;
        second->val = tmp;
    }
};

auto speedup = []() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

// better solution with recursion

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
    TreeNode *first = NULL;
    TreeNode *second = NULL;
    TreeNode *prev = new TreeNode(INT_MIN);

    void inorderTraversal(TreeNode *root)
    {
        if (!root)
            return;

        inorderTraversal(root->left);
        if (!first && root->val < prev->val)
            first = prev;
        if (first && root->val < prev->val)
            second = root;

        prev = root;

        inorderTraversal(root->right);
    }

    void recoverTree(TreeNode *root)
    {
        inorderTraversal(root);

        int tmp = first->val;
        first->val = second->val;
        second->val = tmp;
    }
};

auto speedup = []() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

// O(n) space solution with recursion

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
    void inorderTraversal(TreeNode *root, vector<TreeNode *> &order)
    {
        if (!root)
            return;

        inorderTraversal(root->left, order);
        order.emplace_back(root);
        inorderTraversal(root->right, order);
    }

    void recoverTree(vector<TreeNode *> &order)
    {
        int i = 1, j = 0;
        while (i < order.size() && order[i]->val > order[i - 1]->val)
            ++i;

        j = i;
        for (int k = i; k < order.size(); ++k)
        {
            if (order[j]->val > order[k]->val)
                j = k;
        }

        int tmp = order[i - 1]->val;
        order[i - 1]->val = order[j]->val;
        order[j]->val = tmp;
    }

    void recoverTree(TreeNode *root)
    {
        vector<TreeNode *> order;
        inorderTraversal(root, order);

        recoverTree(order);
    }
};

auto speedup = []() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();