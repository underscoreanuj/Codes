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
    ListNode *insert(ListNode *head, int val)
    {
        if (head == NULL)
            return new ListNode(val);
        ListNode *t = head;
        while (t->next != NULL)
            t = t->next;
        t->next = new ListNode(val);
        return head;
    }

    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *ret = NULL;
        int carry = 0, sum = 0;
        while (l1 != NULL && l2 != NULL)
        {
            sum = l1->val + l2->val + carry;
            ret = insert(ret, sum % 10);
            carry = sum / 10;

            l1 = l1->next;
            l2 = l2->next;
        }

        while (l1 != NULL)
        {
            sum = l1->val + carry;
            ret = insert(ret, sum % 10);
            carry = sum / 10;
            l1 = l1->next;
        }
        while (l2 != NULL)
        {
            sum = l2->val + carry;
            ret = insert(ret, sum % 10);
            carry = sum / 10;
            l2 = l2->next;
        }
        if (carry)
            ret = insert(ret, carry);

        return ret;
    }
};