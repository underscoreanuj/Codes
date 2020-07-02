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
    ListNode *partition(ListNode *head, int x)
    {
        if (!head)
            return NULL;

        ListNode *less = NULL, *less_cur = NULL;
        ListNode *more = NULL, *more_cur = NULL;
        ListNode *cur = head;

        while (cur)
        {
            if (cur->val < x)
            {
                if (!less)
                {
                    less = cur;
                }
                else
                {
                    less_cur->next = cur;
                }
                less_cur = cur;
                cur = cur->next;
                less_cur->next = NULL;
            }
            else
            {
                if (!more)
                {
                    more = cur;
                }
                else
                {
                    more_cur->next = cur;
                }
                more_cur = cur;
                cur = cur->next;
                more_cur->next = NULL;
            }
        }

        if (less)
            less_cur->next = more;
        else
            return more;

        return less;
    }
};