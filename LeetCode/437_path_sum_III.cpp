// O(n) time solution and O(logn) space

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution
{
public:
    int result;
    unordered_map<int, int> MEM;

    void pathSumUtil(TreeNode *root, int pre_sum, int sum)
    {
        if (!root)
            return;

        pre_sum += root->val;
        if (MEM.count(pre_sum - sum))
        {
            result += MEM[pre_sum - sum];
        }

        ++MEM[pre_sum];

        pathSumUtil(root->left, pre_sum, sum);
        pathSumUtil(root->right, pre_sum, sum);

        --MEM[pre_sum];
    }

    int pathSum(TreeNode *root, int sum)
    {
        result = 0;
        int pre_sum = 0;
        MEM[pre_sum] = 1;

        pathSumUtil(root, pre_sum, sum);

        return result;
    }
};

// O(n^2) solution and O(logn) space (stack space of recursion)

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution
{
public:
    int result;
    void pathSumUtil(TreeNode *root, int sum)
    {
        if (root == NULL)
            return;
        if (root->val == sum)
            ++result;
        pathSumUtil(root->left, sum - root->val);
        pathSumUtil(root->right, sum - root->val);
    }

    void traverse(TreeNode *root, int &sum)
    {
        if (root)
        {
            traverse(root->left, sum);
            pathSumUtil(root, sum);
            traverse(root->right, sum);
        }
    }

    int pathSum(TreeNode *root, int sum)
    {
        result = 0;
        traverse(root, sum);
        return result;
    }
};