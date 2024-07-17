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
  ListNode* oddEvenList(ListNode* head) {
    if (head == nullptr) {
      return head;
    }
    ListNode* odd_curr = head;
    ListNode* even_curr = head->next;
    ListNode* odd_head = odd_curr;
    ListNode* even_head = even_curr;
    while (even_curr != nullptr && even_curr->next != nullptr) {
      odd_curr->next = even_curr->next;
      odd_curr = odd_curr->next;
      even_curr->next = odd_curr->next;
      even_curr = even_curr->next;
    }
    odd_curr->next = even_head;
    return odd_head;
  }
};
