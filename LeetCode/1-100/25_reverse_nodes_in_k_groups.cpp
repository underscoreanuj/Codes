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
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        if (head == NULL)
            return NULL;

        ListNode *t = head;

        for (int i = 0; i < k; ++i)
        {
            if (t == NULL)
                return head;
            t = t->next;
        }

        t = head;
        ListNode *prev = NULL;
        ListNode *nxt = head->next;
        for (int i = 0; i < k; ++i)
        {
            t->next = prev;
            prev = t;
            t = nxt;
            if (nxt == NULL)
                break;
            nxt = nxt->next;
        }

        head->next = reverseKGroup(t, k);

        return prev;
    }
};