#include <algorithm>
#include <limits>
#include <vector>
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
  vector<int> nodesBetweenCriticalPoints(ListNode *head) {
    vector<int> result{numeric_limits<int>::max(), numeric_limits<int>::min()};
    int first_critical = -1;
    int last_critical = -1;
    int index = 1;
    while (head->next != nullptr && head->next->next != nullptr) {
      if ((head->val < head->next->val &&
           head->next->val > head->next->next->val) ||
          (head->val > head->next->val &&
           head->next->val < head->next->next->val)) {
        if (first_critical != -1) {
          result[1] = index - first_critical;
        } else {
          first_critical = index;
        }
        if (last_critical != -1) {
          result[0] = min(result[0], index - last_critical);
        }
        last_critical = index;
      }
      head = head->next;
      ++index;
    }
    if (result[0] == numeric_limits<int>::max() ||
        result[1] == numeric_limits<int>::min()) {
      return {-1, -1};
    }
    return result;
  }
};
