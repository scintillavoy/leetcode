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
  ListNode* rotateRight(ListNode* head, int k) {
    int length = 0;
    ListNode* curr = head;
    while (curr != nullptr) {
      curr = curr->next;
      ++length;
    }
    if (length == 0 || k % length == 0) {
      return head;
    }

    // Find a new head.
    int new_head_index = length - k % length;
    curr = head;
    for (int i = 0; i < new_head_index - 1; ++i) {
      curr = curr->next;
    }
    ListNode* new_head = curr->next;

    // `curr` should be a new tail.
    curr->next = nullptr;

    // Set the old head as the next node of the old tail.
    curr = new_head;
    while (curr->next != nullptr) {
      curr = curr->next;
    }
    curr->next = head;

    return new_head;
  }
};
