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
  bool isPalindrome(ListNode *head) {
    if (!head || !head->next)
      return true;
    ListNode *slow = head;
    ListNode *fast = head;

    while (fast && fast->next) {
      slow = slow->next;
      fast = fast->next->next;
    }

    ListNode *tmp = head;
    ListNode *nxt = head->next;
    ListNode *prev = NULL;

    while (tmp != slow) {
      tmp->next = prev;
      prev = tmp;
      tmp = nxt;
      nxt = nxt->next;
    }

    if (fast)
      slow = slow->next;

    while (prev) {
      if (prev->val != slow->val)
        return false;
      prev = prev->next;
      slow = slow->next;
    }

    return true;
  }
};

auto speedup = []() {
  std::ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  return nullptr;
}();
