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
    ListNode *deleteDuplicates(ListNode *head)
    {
        if (head == NULL)
            return NULL;

        ListNode *t = head;

        while (t && t->next)
        {
            while (t->next && t->val == t->next->val)
                t->next = t->next->next;
            t = t->next;
        }

        return head;
    }
};