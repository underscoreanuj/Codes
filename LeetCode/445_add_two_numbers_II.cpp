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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        stack<int> s1, s2;

        ListNode *cur = l1;
        while (cur)
        {
            s1.push(cur->val);
            cur = cur->next;
        }

        cur = l2;
        while (cur)
        {
            s2.push(cur->val);
            cur = cur->next;
        }

        int sum_c = 0;
        if (s1.size())
            sum_c += s1.top(), s1.pop();
        if (s2.size())
            sum_c += s2.top(), s2.pop();
        ListNode *prev = new ListNode(sum_c % 10);
        sum_c /= 10;

        while (s1.size() || s2.size() || sum_c)
        {
            if (s1.size())
                sum_c += s1.top(), s1.pop();
            if (s2.size())
                sum_c += s2.top(), s2.pop();

            cur = new ListNode(sum_c % 10);
            sum_c /= 10;
            cur->next = prev;
            prev = cur;
        }

        return prev;
    }
};

auto speedup = []() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();