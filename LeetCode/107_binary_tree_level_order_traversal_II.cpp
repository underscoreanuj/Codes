// bfs solution

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
    vector<vector<int>> levelOrderBottom(TreeNode *root)
    {
        if (!root)
            return {};
        vector<vector<int>> result;
        vector<int> res;

        queue<TreeNode *> Q;
        TreeNode *cur = NULL;
        int q_size = 0;
        Q.push(root);

        while (!Q.empty())
        {
            res.clear();
            q_size = Q.size();
            while (q_size--)
            {
                cur = Q.front();
                Q.pop();

                res.emplace_back(cur->val);
                if (cur->left)
                    Q.push(cur->left);
                if (cur->right)
                    Q.push(cur->right);
            }

            result.emplace_back(res);
        }

        reverse(result.begin(), result.end());

        return result;
    }
};

auto speedup = []() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

// dfs solution

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
    void dfs(TreeNode *root, vector<vector<int>> &result, int level = 1)
    {
        if (!root)
            return;

        if (result.size() < level)
        {
            result.push_back({});
        }

        dfs(root->left, result, level + 1);
        dfs(root->right, result, level + 1);
        result[level - 1].emplace_back(root->val);
    }

    vector<vector<int>> levelOrderBottom(TreeNode *root)
    {
        if (!root)
            return {};
        vector<vector<int>> result;

        dfs(root, result);
        reverse(result.begin(), result.end());

        return result;
    }
};

auto speedup = []() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();