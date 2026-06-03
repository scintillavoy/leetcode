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
  ListNode* swapPairs(ListNode* head) {
    ListNode dummy_head;
    dummy_head.next = head;
    ListNode* prev = &dummy_head;
    ListNode* curr = head;
    while (curr != nullptr && curr->next != nullptr) {
      ListNode* next = curr->next;
      ListNode* next2 = curr->next->next;
      prev->next = next;
      curr->next = next2;
      next->next = curr;
      prev = curr;
      curr = next2;
    }
    return dummy_head.next;
  }
};
