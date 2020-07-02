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
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode *B = head;
        ListNode *F = head;
        for (int i = 0; i < n; ++i)
            F = F->next;
        if (F == NULL)
            return head->next;
        while (F->next != NULL)
        {
            F = F->next;
            B = B->next;
        }

        ListNode *rem = B->next;
        B->next = rem->next;

        delete (rem);
        return head;
    }
};