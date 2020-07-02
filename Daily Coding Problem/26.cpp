/**
 * Good morning! Here's your coding interview problem for today.
 * This problem was asked by Google.
 * Given a singly linked list and an integer k, remove the kth last element from the list. k is guaranteed to be smaller than the length of the list.
 * The list is very long, so making more than one pass is prohibitively expensive.
 * Do this in constant space and in one pass.
 * 
 * 
 * Online Judge: https://leetcode.com/problems/remove-nth-node-from-end-of-list/
 * 
 */

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
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        if (!head)
            return head;

        ListNode *slow = head;
        ListNode *fast = head;
        ListNode *to_delete = head;

        while (n--)
            fast = fast->next;

        if (!fast)
        {
            head = head->next;
            delete (to_delete);
            return head;
        }

        while (fast->next)
        {
            slow = slow->next;
            fast = fast->next;
        }
        to_delete = slow->next;
        slow->next = slow->next->next;
        delete (to_delete);

        return head;
    }
};

auto speedup = []() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();