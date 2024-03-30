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
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* head = new ListNode();
    ListNode* curr = head;
    int carry = 0;
    while (l1 != nullptr || l2 != nullptr) {
      curr->next = new ListNode();
      curr = curr->next;
      curr->val =
          (l1 == nullptr ? 0 : l1->val) + (l2 == nullptr ? 0 : l2->val) + carry;
      if (curr->val >= 10) {
        carry = 1;
        curr->val -= 10;
      } else {
        carry = 0;
      }
      l1 = (l1 == nullptr ? nullptr : l1->next);
      l2 = (l2 == nullptr ? nullptr : l2->next);
    }
    if (carry == 1) {
      curr->next = new ListNode(1);
    }
    return head->next;
  }
};
