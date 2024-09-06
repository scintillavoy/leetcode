#include <unordered_set>
#include <vector>
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
  ListNode* modifiedList(vector<int>& nums, ListNode* head) {
    unordered_set<int> num_set;
    for (const auto num : nums) {
      num_set.insert(num);
    }
    ListNode* before_head = new ListNode(0, head);
    ListNode* curr = before_head;
    while (curr->next != nullptr) {
      if (num_set.contains(curr->next->val)) {
        curr->next = curr->next->next;
      } else {
        curr = curr->next;
      }
    }
    return before_head->next;
  }
};
