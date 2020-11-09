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
    ListNode *insertionSortList(ListNode *head)
    {
        if (!head)
            return NULL;

        ListNode dummy(INT_MIN);
        ListNode *prev = &dummy;
        ListNode *cur = head;
        ListNode *nxt = NULL;

        while (cur)
        {
            nxt = cur->next;

            while (prev->next && cur->val > prev->next->val)
            {
                prev = prev->next;
            }

            cur->next = prev->next;
            prev->next = cur;

            prev = &dummy;
            cur = nxt;
        }

        return dummy.next;
    }
};

auto speedup = []() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();