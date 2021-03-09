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
  TreeNode *addOneRowUtil(TreeNode *root, int v, int d) {
    if (!root)
      return NULL;

    if (d == 2) {
      root->left = new TreeNode(v, root->left, NULL);
      root->right = new TreeNode(v, NULL, root->right);
    }

    root->left = addOneRowUtil(root->left, v, d - 1);
    root->right = addOneRowUtil(root->right, v, d - 1);

    return root;
  }

  TreeNode *addOneRow(TreeNode *root, int v, int d) {
    if (d == 1)
      return new TreeNode(v, root, NULL);

    return addOneRowUtil(root, v, d);
  }
};

auto speedu = []() {
  std::ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  return nullptr;
}();
