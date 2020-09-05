// single pass iterative approach

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
    vector<int> getAllElements(TreeNode *root1, TreeNode *root2)
    {
        vector<int> result;
        stack<TreeNode *> s1, s2;
        TreeNode *cur1 = root1;
        TreeNode *cur2 = root2;
        TreeNode *dummy = new TreeNode(INT_MAX);

        while (s1.size() || cur1 != NULL || s2.size() || cur2 != NULL)
        {
            while (cur1 != NULL)
            {
                s1.push(cur1);
                cur1 = cur1->left;
            }
            while (cur2 != NULL)
            {
                s2.push(cur2);
                cur2 = cur2->left;
            }

            cur1 = s1.size() ? s1.top() : dummy;
            cur2 = s2.size() ? s2.top() : dummy;

            if (cur1->val <= cur2->val)
            {
                result.emplace_back(cur1->val);
                s1.pop();
                cur1 = cur1->right;
                cur2 = NULL;
            }
            else
            {
                result.emplace_back(cur2->val);
                s2.pop();
                cur1 = NULL;
                cur2 = cur2->right;
            }
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

// two pass recursive traversal + merge approach

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
    void preorder(TreeNode *root, vector<int> &arr)
    {
        if (root == NULL)
            return;
        preorder(root->left, arr);
        arr.emplace_back(root->val);
        preorder(root->right, arr);
    }

    vector<int> merge(vector<int> &a, vector<int> &b)
    {
        vector<int> result;
        int i = 0, j = 0;
        while (i < a.size() && j < b.size())
        {
            if (a[i] <= b[j])
                result.emplace_back(a[i++]);
            else
                result.emplace_back(b[j++]);
        }
        while (i < a.size())
            result.emplace_back(a[i++]);
        while (j < b.size())
            result.emplace_back(b[j++]);

        return result;
    }

    vector<int> getAllElements(TreeNode *root1, TreeNode *root2)
    {
        vector<int> arr1, arr2;
        preorder(root1, arr1);
        preorder(root2, arr2);

        return merge(arr1, arr2);
    }
};

auto speedup = []() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();