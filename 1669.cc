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
  ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
    ListNode* beforeFirst1 = list1;
    for (int i = 0; i < a - 1; ++i) {
      beforeFirst1 = beforeFirst1->next;
    }
    ListNode* afterLast1 = beforeFirst1;
    for (int i = 0; i < b - a + 2; ++i) {
      afterLast1 = afterLast1->next;
    }
    ListNode* last2 = list2;
    while (last2->next != nullptr) {
      last2 = last2->next;
    }
    beforeFirst1->next = list2;
    last2->next = afterLast1;
    return list1;
  }
};
