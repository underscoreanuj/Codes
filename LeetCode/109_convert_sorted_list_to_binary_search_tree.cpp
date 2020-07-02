// time: O(N), space: O(logN) solution

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    ListNode *head;

public:
    int getLength(ListNode *head)
    {
        int len = 0;
        ListNode *cur = head;
        while (cur)
        {
            ++len;
            cur = cur->next;
        }

        return len;
    }

    TreeNode *sortedListToBSTUtil(int l, int r)
    {
        if (l > r)
            return NULL;

        int mid = l + ((r - l) >> 1);
        TreeNode *left = sortedListToBSTUtil(l, mid - 1);
        TreeNode *root = new TreeNode(head->val);
        head = head->next;
        TreeNode *right = sortedListToBSTUtil(mid + 1, r);

        root->left = left;
        root->right = right;

        return root;
    }

    TreeNode *sortedListToBST(ListNode *head)
    {
        this->head = head;

        return sortedListToBSTUtil(0, getLength(head) - 1);
    }
};

auto speedup = []() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();