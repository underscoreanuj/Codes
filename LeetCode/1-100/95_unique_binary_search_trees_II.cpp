// divide and conquer solution

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
    vector<TreeNode *> generateTreesUtil(int start, int end)
    {
        if (start > end)
            return {{NULL}};

        vector<TreeNode *> result;

        for (int i = start; i <= end; ++i)
        {
            vector<TreeNode *> left_subtrees = generateTreesUtil(start, i - 1);
            vector<TreeNode *> right_subtrees = generateTreesUtil(i + 1, end);

            for (auto l : left_subtrees)
            {
                for (auto r : right_subtrees)
                {
                    TreeNode *root = new TreeNode(i);
                    root->left = l;
                    root->right = r;

                    result.push_back(root);
                }
            }
        }

        return result;
    }

    vector<TreeNode *> generateTrees(int n)
    {
        if (n == 0)
            return {};
        return generateTreesUtil(1, n);
    }
};

auto speedup = []() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();