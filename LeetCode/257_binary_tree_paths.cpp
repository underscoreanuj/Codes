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
    vector<string> binaryTreePaths(TreeNode *root)
    {
        if (!root)
            return {};

        vector<string> result;
        queue<pair<TreeNode *, string>> Q;
        Q.push({root, ""});

        while (!Q.empty())
        {
            auto cur = Q.front();
            Q.pop();
            string path = cur.second;
            path += to_string(cur.first->val);

            // leaf node
            if (cur.first->left == NULL && cur.first->right == NULL)
                result.push_back(path);

            if (cur.first->left)
                Q.push({cur.first->left, path + "->"});

            if (cur.first->right)
                Q.push({cur.first->right, path + "->"});
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
    void binaryTreePathsUtil(TreeNode *root, string path, vector<string> &result)
    {
        if (root->left == NULL && root->right == NULL)
        { // leaf node
            result.push_back(path + (path.length() ? "->" : "") + to_string(root->val));
            return;
        }

        if (root->left)
            binaryTreePathsUtil(root->left, path + (path.length() ? "->" : "") + to_string(root->val), result);
        if (root->right)
            binaryTreePathsUtil(root->right, path + (path.length() ? "->" : "") + to_string(root->val), result);
    }

    vector<string> binaryTreePaths(TreeNode *root)
    {
        if (!root)
            return {};

        vector<string> result;
        binaryTreePathsUtil(root, "", result);

        return result;
    }
};

auto speedup = []() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();