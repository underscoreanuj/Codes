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
    ListNode *rotateRight(ListNode *head, int k)
    {
        if (head == NULL)
            return NULL;

        int len = 1;
        ListNode *cur = head;
        while (cur->next)
        {
            ++len;
            cur = cur->next;
        }
        k = k % len;
        if (k == 0)
            return head;
        k = len - k;
        cur->next = head;
        while (k--)
            cur = cur->next;
        head = cur->next;
        cur->next = NULL;

        return head;
    }
};