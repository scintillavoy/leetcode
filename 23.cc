#include <queue>
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
  ListNode* mergeKLists(vector<ListNode*>& lists) {
    auto cmp = [](const ListNode* a, const ListNode* b) {
      return a->val > b->val;
    };
    priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> pq;
    for (int i = 0; i < lists.size(); ++i) {
      if (lists[i] != nullptr) {
        pq.push(lists[i]);
      }
    }
    ListNode* dummy_head = new ListNode();
    ListNode* curr = dummy_head;
    while (!pq.empty()) {
      auto t = pq.top();
      pq.pop();
      curr->next = t;
      curr = curr->next;
      if (t->next != nullptr) {
        pq.push(t->next);
      }
    }
    return dummy_head->next;
  }
};
