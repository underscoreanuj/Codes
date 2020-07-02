// recursive solution

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
class Solution
{
public:
    ListNode *removeElements(ListNode *head, int val)
    {
        while (head && head->val == val)
            head = head->next;
        if (!head)
            return NULL;
        head->next = removeElements(head->next, val);

        return head;
    }
};

// iterative solution

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
class Solution
{
public:
    ListNode *removeElements(ListNode *head, int val)
    {
        while (head && head->val == val)
        {
            head = head->next;
        }

        if (!head)
            return NULL;

        ListNode *cur = head->next;
        ListNode *prev = head;

        while (cur)
        {
            if (cur->val == val)
                prev->next = cur->next;
            else
                prev = cur;

            cur = cur->next;
        }

        return head;
    }
};