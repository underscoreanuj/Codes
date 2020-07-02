/*
 * Good morning! Here's your coding interview problem for today.
 * This problem was asked by Google.
 * Given two singly linked lists that intersect at some point, find the intersecting node. The lists are non-cyclical.
 * For example, given A = 3 -> 7 -> 8 -> 10 and B = 99 -> 1 -> 8 -> 10, return the node with value 8.
 * In this example, assume nodes with the same value are the exact same node objects.
 * Do this in O(M + N) time (where M and N are the lengths of the lists) and constant space.
 * 
 * 
 * Online Judge: https://leetcode.com/problems/intersection-of-two-linked-lists/
 * 
 * 
*/

// a good, small & intuitive solution

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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        ListNode *curA = headA, *curB = headB;

        while (curA != curB)
        {
            curA = curA ? curA->next : headB;
            curB = curB ? curB->next : headA;
        }

        return curA;
    }
};

// my solution

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
    int getLength(ListNode *head)
    {
        if (head == NULL)
            return 0;
        int ct = 0;
        while (head)
        {
            ++ct;
            head = head->next;
        }

        return ct;
    }

    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        if (!headA || !headB)
            return NULL;

        int lengthA = getLength(headA);
        int lengthB = getLength(headB);

        if (lengthA < lengthB)
        {
            swap(lengthA, lengthB);
            ListNode *tmp = headA;
            headA = headB;
            headB = tmp;
        }

        int lenDiff = lengthA - lengthB;

        while (lenDiff--)
            headA = headA->next;

        while (headA && headB)
        {
            if (headA == headB)
                return headA;
            headA = headA->next;
            headB = headB->next;
        }

        return NULL;
    }
};