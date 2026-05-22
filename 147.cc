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
  ListNode* insertionSortList(ListNode* head) {
    ListNode* curr = head->next;
    head->next = nullptr;
    while (curr != nullptr) {
      ListNode* next = curr->next;
      if (curr->val < head->val) {
        curr->next = head;
        head = curr;
      } else {
        ListNode* prev = head;
        while (prev->next != nullptr && prev->next->val < curr->val) {
          prev = prev->next;
        }
        curr->next = prev->next;
        prev->next = curr;
      }
      curr = next;
    }
    return head;
  }
};
