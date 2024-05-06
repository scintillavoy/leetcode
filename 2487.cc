#include <stack>
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
  ListNode* removeNodes(ListNode* head) {
    stack<ListNode*> s;
    while (head != nullptr) {
      while (!s.empty() && s.top()->val < head->val) {
        s.pop();
      }
      s.push(head);
      head = head->next;
    }
    while (!s.empty()) {
      ListNode* t = s.top();
      s.pop();
      t->next = head;
      head = t;
    }
    return head;
  }
};
