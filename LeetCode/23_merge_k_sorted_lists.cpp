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
    class MyComp
    {
    public:
        bool operator()(const pair<int, ListNode *> &o1, const pair<int, ListNode *> &o2)
        {
            return o1.first > o2.first;
        }
    };

    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        if (lists.size() == 0)
            return NULL;
        if (lists.size() == 1)
            return lists[0];

        priority_queue<pair<int, ListNode *>, vector<pair<int, ListNode *>>, MyComp> PQ;

        for (int i = 0; i < lists.size(); ++i)
            if (lists[i])
                PQ.push({lists[i]->val, lists[i]});

        if (PQ.size() == 0)
            return NULL;

        ListNode *head = PQ.top().second;
        PQ.pop();
        ListNode *t = head;
        if (t->next != NULL)
            PQ.push({t->next->val, t->next});

        while (!PQ.empty())
        {
            t->next = PQ.top().second;
            t = t->next;
            PQ.pop();
            if (t->next != NULL)
                PQ.push({t->next->val, t->next});
        }

        return head;
    }
};