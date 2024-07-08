#include <unordered_map>
using namespace std;

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
  ListNode* deleteDuplicatesUnsorted(ListNode* head) {
    unordered_map<int, int> counts;
    ListNode* curr = head;
    while (curr != nullptr) {
      ++counts[curr->val];
      curr = curr->next;
    }
    ListNode* dummy = new ListNode(0, head);
    curr = dummy;
    while (curr->next != nullptr) {
      if (counts[curr->next->val] >= 2) {
        curr->next = curr->next->next;
      } else {
        curr = curr->next;
      }
    }
    return dummy->next;
  }
};
