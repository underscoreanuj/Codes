// actual node swapping

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
class Solution {
public:
  ListNode *swapNodes(ListNode *head, int k) {
    if (!head)
      return NULL;

    int len = k;
    ListNode *cur1 = head;
    ListNode *cur2 = head;
    ListNode *prev1 = NULL;
    ListNode *prev2 = NULL;

    for (int i = 1; i < k; ++i) {
      prev1 = cur1;
      cur1 = cur1->next;
    }

    ListNode *tmp = cur1;
    cur2 = head;

    while (tmp->next) {
      ++len;
      tmp = tmp->next;
      prev2 = cur2;
      cur2 = cur2->next;
    }

    if (k > (len >> 1)) {
      swap(prev1, prev2);
      swap(cur1, cur2);
    }

    tmp = cur2->next;
    cur2->next = cur1->next == cur2 ? cur1 : cur1->next;
    cur1->next = tmp;

    if (prev1 && prev2) {
      prev1->next = cur2;
      prev2->next = cur1 == prev2 ? cur1->next : cur1;
    } else if (prev1 && !prev2) {
      prev1->next = cur2;
      head = cur1;
    } else if (!prev1 && prev2) {
      prev2->next = cur1 == prev2 ? cur1->next : cur1;
      head = cur2;
    }

    return head;
  }
};

auto speedup = []() {
  std::ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  return nullptr;
}();

// simple value swapping

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
class Solution {
public:
  ListNode *swapNodes(ListNode *head, int k) {
    if (!head)
      return NULL;

    ListNode *cur1 = head;
    ListNode *cur2 = head;

    for (int i = 1; i < k; ++i)
      cur1 = cur1->next;

    ListNode *tmp = cur1;
    cur2 = head;
    while (tmp->next) {
      tmp = tmp->next;
      cur2 = cur2->next;
    }

    swap(cur1->val, cur2->val);

    return head;
  }
};

auto speedup = []() {
  std::ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  return nullptr;
}();
