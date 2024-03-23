struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
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
  void reorderList(ListNode *head) {
    ListNode *slow = head;
    ListNode *fast = head;
    while (fast != nullptr && fast->next != nullptr) {
      slow = slow->next;
      fast = fast->next->next;
    }

    ListNode *prev = nullptr;
    ListNode *curr = slow->next;
    slow->next = nullptr;
    while (curr != nullptr) {
      ListNode *next = curr->next;
      curr->next = prev;
      prev = curr;
      curr = next;
    }

    ListNode *head1 = head;
    ListNode *head2 = prev;
    while (head2 != nullptr) {
      ListNode *next1 = head1->next;
      ListNode *next2 = head2->next;
      head1->next = head2;
      head2->next = next1;
      head1 = next1;
      head2 = next2;
    }
  }
};
