// constant space & linear time complexity

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
  Node *copyRandomList(Node *head) {
    if (!head)
      return NULL;

    Node *result;
    Node *tmp = head;
    Node *nxt = NULL;

    while (tmp) {
      nxt = tmp->next;
      tmp->next = new Node(tmp->val);
      tmp->next->next = nxt;
      tmp = tmp->next->next;
    }

    tmp = head;
    nxt = head->next;
    while (tmp) {
      nxt->random = tmp->random ? tmp->random->next : NULL;
      nxt = nxt->next ? nxt->next->next : NULL;
      tmp = tmp->next->next;
    }

    tmp = head;
    nxt = head->next;
    result = nxt;

    while (tmp) {
      tmp->next = tmp->next->next;
      nxt->next = nxt->next ? nxt->next->next : NULL;
      tmp = tmp->next;
      nxt = nxt->next;
    }

    return result;
  }
};

auto speedup = []() {
  std::ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  return nullptr;
}();
