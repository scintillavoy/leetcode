#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* sum = new ListNode;
        ListNode* curr = sum;
        int carry = 0;
        while (l1 || l2) {
            curr->next = new ListNode(carry);
            curr = curr->next;
            if (l1) {
                curr->val += l1->val;
                l1 = l1->next;
            }
            if (l2) {
                curr->val += l2->val;
                l2 = l2->next;
            }
            if (curr->val >= 10) {
                curr->val -= 10;
                carry = 1;
            } else {
                carry = 0;
            }
        }
        if (carry) {
            curr->next = new ListNode(carry);
        }
        return sum->next;
    }
};

int main() {
    Solution sol;
    ListNode* l1 = new ListNode(2, new ListNode(4, new ListNode(3)));
    ListNode* l2 = new ListNode(5, new ListNode(6, new ListNode(4)));
    ListNode* sum = sol.addTwoNumbers(l1, l2);
    while (sum) {
        cout << sum->val << ' ';
        sum = sum->next;
    }
    cout << endl;
    return 0;
}
