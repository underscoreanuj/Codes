/**
 * Good morning! Here's your coding interview problem for today.
 * This problem was asked by Dropbox.
 * Given the root to a binary search tree, find the second largest node in the tree.
 * 
 * 
 */

class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;
};

TreeNode *getLargest(TreeNode *node)
{
    if (node->right != NULL)
        return getLargest(node->right);
    return node;
}

TreeNode *getSecondLargest(TreeNode *root)
{
    // root is pointing to the largest element in bst with a left child
    if (root->right == NULL && root->left != NULL)
        return getLargest(root->left);

    // root is pointing at the parent of the larget element in bst with no children
    if (root->right != NULL && root->right->right == NULL && root->right->left == NULL)
        return root;

    return getSecondLargest(root->right);
}
