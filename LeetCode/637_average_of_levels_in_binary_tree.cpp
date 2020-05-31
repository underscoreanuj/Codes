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
    vector<double> averageOfLevels(TreeNode *root)
    {
        if (!root)
            return {};

        vector<double> result;
        queue<TreeNode *> Q;
        TreeNode *cur = NULL;
        int q_size = 0;
        double sum = 0;

        Q.push(root);

        while (!Q.empty())
        {
            q_size = Q.size();
            sum = 0;
            for (int i = 0; i < q_size; ++i)
            {
                cur = Q.front();
                Q.pop();

                sum += cur->val;
                if (cur->left)
                    Q.push(cur->left);
                if (cur->right)
                    Q.push(cur->right);
            }
            result.emplace_back(sum / q_size);
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
    void averageOfLevelsUtil(TreeNode *root, vector<double> &result, vector<int> &count, int level = 0)
    {
        if (!root)
            return;

        if (result.size() <= level)
        {
            result.emplace_back(0);
            count.emplace_back(0);
        }

        averageOfLevelsUtil(root->left, result, count, level + 1);
        averageOfLevelsUtil(root->right, result, count, level + 1);
        result[level] += root->val;
        ++count[level];
    }

    vector<double> averageOfLevels(TreeNode *root)
    {
        vector<double> result;
        vector<int> count;
        averageOfLevelsUtil(root, result, count);

        for (int i = 0; i < result.size(); ++i)
            result[i] /= count[i];

        return result;
    }
};

auto speedup = []() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();