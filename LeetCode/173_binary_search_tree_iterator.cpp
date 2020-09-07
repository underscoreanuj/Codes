// controlled recursive solution (efficient approach)

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
class BSTIterator
{
public:
    stack<TreeNode *> mem;
    TreeNode *cur;

    BSTIterator(TreeNode *root)
    {
        cur = root;
    }

    /** @return the next smallest number */
    int next()
    {
        while (cur)
        {
            mem.push(cur);
            cur = cur->left;
        }

        cur = mem.top();
        mem.pop();

        int result = cur->val;
        cur = cur->right;

        return result;
    }

    /** @return whether we have a next smallest number */
    bool hasNext()
    {
        return cur || mem.size();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */

// simple O(n) time and O(n) space solution with O(1) next() & hasNext() each

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
class BSTIterator
{
    TreeNode *root;
    vector<TreeNode *> inorder;
    int itr;

    void generateIteration(TreeNode *root)
    {
        if (root)
        {
            generateIteration(root->left);
            inorder.emplace_back(root);
            generateIteration(root->right);
        }
    }

public:
    BSTIterator(TreeNode *root)
    {
        this->root = root;
        generateIteration(root);
        itr = 0;
    }

    /** @return the next smallest number */
    int next()
    {
        return inorder[itr++]->val;
    }

    /** @return whether we have a next smallest number */
    bool hasNext()
    {
        return itr < inorder.size();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */