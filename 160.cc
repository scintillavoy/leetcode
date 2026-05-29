#define NULL nullptr

struct ListNode {
  int val;
  ListNode* next;
  ListNode(int x) : val(x), next(NULL) {}
};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
 public:
  ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
    ListNode* curr_a = headA;
    ListNode* curr_b = headB;
    int length_a = 1;
    int length_b = 1;
    while (curr_a->next != nullptr) {
      curr_a = curr_a->next;
      ++length_a;
    }
    while (curr_b->next != nullptr) {
      curr_b = curr_b->next;
      ++length_b;
    }
    if (curr_a != curr_b) {
      return nullptr;
    }
    curr_a = headA;
    curr_b = headB;
    if (length_a < length_b) {
      for (int i = 0; i < length_b - length_a; ++i) {
        curr_b = curr_b->next;
      }
    } else if (length_b < length_a) {
      for (int i = 0; i < length_a - length_b; ++i) {
        curr_a = curr_a->next;
      }
    }
    while (curr_a != curr_b) {
      curr_a = curr_a->next;
      curr_b = curr_b->next;
    }
    return curr_a;
  }
};
