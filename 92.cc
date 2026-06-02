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
  ListNode* reverseBetween(ListNode* head, int left, int right) {
    ListNode dummy_head;
    dummy_head.next = head;
    ListNode* curr = &dummy_head;
    for (int i = 1; i < left; ++i) {
      curr = curr->next;
    }
    ListNode* prev_left_node = curr;
    ListNode* left_node = prev_left_node->next;
    curr = left_node;
    ListNode* next = curr->next;
    for (int i = left + 1; i <= right; ++i) {
      ListNode* prev = curr;
      curr = next;
      next = curr->next;
      curr->next = prev;
    }
    prev_left_node->next = curr;
    left_node->next = next;
    return dummy_head.next;
  }
};
