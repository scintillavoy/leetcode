#include <vector>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
 public:
  bool isSubPath(ListNode *head, TreeNode *root) {
    ListNode *curr = head;
    while (curr != nullptr) {
      ++length;
      curr = curr->next;
    }
    return traverse(head, root);
  }

 private:
  int length = 0;
  vector<int> values;

  bool traverse(ListNode *head, TreeNode *root) {
    if (root == nullptr) {
      return false;
    }
    values.push_back(root->val);
    if (values.size() >= length) {
      ListNode *curr = head;
      for (int i = values.size() - length; i < values.size(); ++i) {
        if (curr->val != values[i]) {
          break;
        }
        if (i == values.size() - 1) {
          return true;
        }
        curr = curr->next;
      }
    }
    bool result = traverse(head, root->left) || traverse(head, root->right);
    values.pop_back();
    return result;
  }
};
