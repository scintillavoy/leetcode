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
  bool isPalindrome(ListNode *head) {
    ListNode *slow = head;
    ListNode *fast = head;
    while (fast != nullptr) {
      slow = slow->next;
      fast = fast->next;
      if (fast != nullptr) {
        fast = fast->next;
      }
    }
    ListNode *prev = nullptr;
    ListNode *curr = slow;
    while (curr != nullptr) {
      ListNode *next = curr->next;
      curr->next = prev;
      prev = curr;
      curr = next;
    }
    ListNode *head2 = prev;
    while (head2 != nullptr) {
      if (head->val != head2->val) {
        return false;
      }
      head = head->next;
      head2 = head2->next;
    }
    return true;
  }
};
