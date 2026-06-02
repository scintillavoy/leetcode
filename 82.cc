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
  ListNode* deleteDuplicates(ListNode* head) {
    ListNode dummy_head;
    dummy_head.next = head;
    ListNode* curr = &dummy_head;
    while (curr->next != nullptr && curr->next->next != nullptr) {
      if (curr->next->val != curr->next->next->val) {
        curr = curr->next;
        continue;
      }
      ListNode* last_duplicate = curr->next->next;
      while (last_duplicate->next != nullptr &&
             last_duplicate->val == last_duplicate->next->val) {
        last_duplicate = last_duplicate->next;
      }
      curr->next = last_duplicate->next;
    }
    return dummy_head.next;
  }
};
