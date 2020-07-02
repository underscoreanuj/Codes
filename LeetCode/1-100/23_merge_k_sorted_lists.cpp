
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
    ListNode *mergeTwoSortedLists(ListNode *l1, ListNode *l2)
    {
        if (l1 == NULL)
            return l2;
        if (l2 == NULL)
            return l1;

        if (l1->val <= l2->val)
        {
            l1->next = mergeTwoSortedLists(l1->next, l2);
            return l1;
        }
        else
        {
            l2->next = mergeTwoSortedLists(l1, l2->next);
            return l2;
        }
    }

    ListNode *divideAndMerge(vector<ListNode *> &lists, int start, int end)
    {
        if (start == end)
            return lists[start];
        if (end - start == 1)
            return mergeTwoSortedLists(lists[start], lists[end]);

        int mid = start + ((end - start) >> 1);
        ListNode *left = divideAndMerge(lists, start, mid);
        ListNode *right = divideAndMerge(lists, mid + 1, end);

        return mergeTwoSortedLists(left, right);
    }

    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        if (lists.size() == 0)
            return NULL;
        if (lists.size() == 1)
            return lists[0];

        return divideAndMerge(lists, 0, lists.size() - 1);
    }
};

// --------------------------------------------------------------------------------------------------------

// /**
//  * Definition for singly-linked list.
//  * struct ListNode {
//  *     int val;
//  *     ListNode *next;
//  *     ListNode(int x) : val(x), next(NULL) {}
//  * };
//  */
// class Solution
// {
// public:
//     class MyComp
//     {
//     public:
//         bool operator()(const pair<int, ListNode *> &o1, const pair<int, ListNode *> &o2)
//         {
//             return o1.first > o2.first;
//         }
//     };

//     ListNode *mergeKLists(vector<ListNode *> &lists)
//     {
//         if (lists.size() == 0)
//             return NULL;
//         if (lists.size() == 1)
//             return lists[0];

//         priority_queue<pair<int, ListNode *>, vector<pair<int, ListNode *>>, MyComp> PQ;

//         for (int i = 0; i < lists.size(); ++i)
//             if (lists[i])
//                 PQ.push({lists[i]->val, lists[i]});

//         if (PQ.size() == 0)
//             return NULL;

//         ListNode *head = PQ.top().second;
//         PQ.pop();
//         ListNode *t = head;
//         if (t->next != NULL)
//             PQ.push({t->next->val, t->next});

//         while (!PQ.empty())
//         {
//             t->next = PQ.top().second;
//             t = t->next;
//             PQ.pop();
//             if (t->next != NULL)
//                 PQ.push({t->next->val, t->next});
//         }

//         return head;
//     }
// };