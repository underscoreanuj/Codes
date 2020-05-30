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
        if (!head)
            return NULL;

        ListNode *prev = NULL;
        ListNode *cur = head;
        ListNode *nxt = head->next;

        while (nxt)
        {
            if (cur->val == nxt->val)
            {
                while (nxt && nxt->val == cur->val)
                    nxt = nxt->next;
                if (prev)
                {
                    prev->next = nxt;
                }
                else
                {
                    head = nxt;
                }
            }
            else
            {
                prev = cur;
            }
            cur = nxt;
            if (nxt)
                nxt = nxt->next;
        }

        return head;
    }
};