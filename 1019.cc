#include <stack>
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
  vector<int> nextLargerNodes(ListNode* head) {
    vector<int> result;
    stack<pair<int, int>> stk;  // (index, val) pairs
    ListNode* curr = head;
    int index = 1;
    while (curr != nullptr) {
      result.push_back(0);
      while (!stk.empty() && stk.top().second < curr->val) {
        result[stk.top().first - 1] = curr->val;
        stk.pop();
      }
      stk.push({index, curr->val});
      curr = curr->next;
      ++index;
    }
    return result;
  }
};
