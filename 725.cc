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
  vector<ListNode *> splitListToParts(ListNode *head, int k) {
    int list_length = 0;
    ListNode *curr = head;
    while (curr != nullptr) {
      ++list_length;
      curr = curr->next;
    }
    int remainder = list_length % k;
    curr = head;
    vector<ListNode *> result(k, nullptr);
    for (int i = 0; i < result.size(); ++i) {
      int sublist_length = list_length / k;
      if (i < remainder) {
        ++sublist_length;
      }
      if (sublist_length == 0) {
        break;
      }
      result[i] = curr;
      while (sublist_length > 1) {
        curr = curr->next;
        --sublist_length;
      }
      ListNode *next = curr->next;
      curr->next = nullptr;
      curr = next;
    }
    return result;
  }
};
