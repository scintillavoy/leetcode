#include <algorithm>
#include <limits>
using namespace std;

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
  int pairSum(ListNode *head) {
    ListNode *slow = head;
    ListNode *fast = head;
    while (fast->next != nullptr && fast->next->next != nullptr) {
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
    ListNode *head2 = prev;
    int max_sum = numeric_limits<int>::min();
    while (head != nullptr && head2 != nullptr) {
      max_sum = max(max_sum, head->val + head2->val);
      head = head->next;
      head2 = head2->next;
    }
    return max_sum;
  }
};
