/*
 *
 * Good morning! Here's your coding interview problem for today.
 * This problem was asked by Google.
 * A unival tree (which stands for "universal value") is a tree where all nodes under it have the same value.
 * Given the root to a binary tree, count the number of unival subtrees.
 * For example, the following tree has 5 unival subtrees:

            ----------------
            |      0       |
            |     / \      |
            |    1   0     |
            |       / \    |
            |      1   0   |
            |     / \      |
            |    1   1     |
            ----------------
 *
 * 
 * Online Judge: https://leetcode.com/problems/count-univalue-subtrees/                     (subscription required)
 * Online Judge used: https://www.lintcode.com/en/old/problem/count-univalue-subtrees/
 * 
*/

/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */
/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */
/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */

class Solution
{
public:
    /**
     * @param root: the given tree
     * @return: the number of uni-value subtrees.
     */

    pair<int, bool> countUnivalSubtreesUtil(TreeNode *root)
    {
        if (root == NULL)
            return {0, true};

        // this check is optional as it gets handled even if removed. Just reduces the two calls per leaf nodes
        if (root->left == NULL && root->right == NULL) // leaf node / single node
            return {1, true};

        pair<int, bool> left = countUnivalSubtreesUtil(root->left);
        pair<int, bool> right = countUnivalSubtreesUtil(root->right);

        // if both children are univalue
        if (left.second && right.second)
        {
            if (root->left && root->left->val != root->val)
            {
                return {left.first + right.first, false};
            }
            if (root->right && root->right->val != root->val)
            {
                return {left.first + right.first, false};
            }
            return {left.first + right.first + 1, true};
        }

        // current node cannot form a uni-value tree
        return {left.first + right.first, false};
    }

    int countUnivalSubtrees(TreeNode *root)
    {
        if (root == NULL)
            return 0;
        return countUnivalSubtreesUtil(root).first;
    }
};