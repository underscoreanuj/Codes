/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
  TreeNode *convertBSTUtil(TreeNode *root, int &sum) {
    if (!root)
      return NULL;

    convertBSTUtil(root->right, sum);

    root->val += sum;
    sum = root->val;

    convertBSTUtil(root->left, sum);

    return root;
  }

  TreeNode *convertBST(TreeNode *root) {
    int sum = 0;

    convertBSTUtil(root, sum);

    return root;
  }
};

auto speedup = []() {
  std::ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  return nullptr;
}();
