/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
    ListNode *reverseList(ListNode *head)
    {
        if (head == NULL)
            return NULL;

        ListNode *prev = NULL;
        ListNode *cur = head;
        ListNode *next = cur->next;

        while (cur)
        {
            cur->next = prev;
            prev = cur;
            cur = next;
            if (cur)
                next = cur->next;
        }

        return prev;
    }
};