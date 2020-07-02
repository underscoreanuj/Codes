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
    ListNode *reverseBetween(ListNode *head, int m, int n)
    {
        if (m == n)
            return head;

        int count = 1;
        ListNode *cur = head;
        ListNode *prev = NULL;
        ListNode *next = head->next;
        ListNode *start_a = NULL;
        ListNode *start_b = NULL;

        while (count <= n)
        {
            if (count == m)
            {
                start_a = prev;
                start_b = cur;
            }
            else if (count > m)
            {
                cur->next = prev;
            }
            prev = cur;
            cur = next;
            if (cur)
                next = cur->next;
            ++count;
        }

        if (start_a)
            start_a->next = prev;
        if (start_b)
            start_b->next = cur;

        // if m == 1 start_a is always null hence last prev is the new head
        if (m == 1)
            return prev;

        return head;
    }
};