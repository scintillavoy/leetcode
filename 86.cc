struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

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
  ListNode* partition(ListNode* head, int x) {
    ListNode lt_dummy_head;
    ListNode* lt_tail = &lt_dummy_head;
    ListNode gte_dummy_head;
    ListNode* gte_tail = &gte_dummy_head;
    while (head != nullptr) {
      if (head->val < x) {
        lt_tail->next = head;
        lt_tail = lt_tail->next;
      } else {
        gte_tail->next = head;
        gte_tail = gte_tail->next;
      }
      head = head->next;
    }
    lt_tail->next = gte_dummy_head.next;
    gte_tail->next = nullptr;
    return lt_dummy_head.next;
  }
};
