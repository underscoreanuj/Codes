// identical to 538 (did a recursive traversal there, so doing a Morris
// traversal here)

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
  TreeNode *bstToGst(TreeNode *root) {
    TreeNode *cur = root;
    TreeNode *tmp = NULL;
    int sum = 0;

    while (cur) {
      if (cur->right) {
        tmp = cur->right;
        while (tmp->left && tmp->left != cur) {
          tmp = tmp->left;
        }

        if (tmp->left == cur) {
          tmp->left = NULL;

          cur->val += sum;
          sum = cur->val;

          cur = cur->left;
        } else {
          tmp->left = cur;
          cur = cur->right;
        }
      } else {
        cur->val += sum;
        sum = cur->val;

        cur = cur->left;
      }
    }

    return root;
  }
};

auto speedup = []() {
  std::ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  return nullptr;
}();
