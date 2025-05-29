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
  ListNode* deleteNodes(ListNode* head, int m, int n) {
    ListNode* slow = head;
    while (slow != nullptr) {
      for (int i = 0; i < m - 1; ++i) {
        slow = slow->next;
        if (slow == nullptr) {
          return head;
        }
      }
      ListNode* fast = slow;
      for (int i = 0; i < n; ++i) {
        fast = fast->next;
        if (fast == nullptr) {
          slow->next = nullptr;
          return head;
        }
      }
      slow->next = fast->next;
      slow = slow->next;
    }
    return head;
  }
};
