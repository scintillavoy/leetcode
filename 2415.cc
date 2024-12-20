#include <deque>
using namespace std;

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
  TreeNode *reverseOddLevels(TreeNode *root) {
    int level = 0;
    deque<TreeNode *> dq;
    dq.push_back(root);
    while (!dq.empty()) {
      if (level % 2 == 1) {
        for (int i = 0; i < dq.size() / 2; ++i) {
          int temp = dq[i]->val;
          dq[i]->val = dq[dq.size() - 1 - i]->val;
          dq[dq.size() - 1 - i]->val = temp;
        }
      }
      for (int i = dq.size(); i > 0; --i) {
        TreeNode *curr = dq.front();
        dq.pop_front();
        if (curr->left != nullptr) {
          dq.push_back(curr->left);
        }
        if (curr->right != nullptr) {
          dq.push_back(curr->right);
        }
      }
      ++level;
    }
    return root;
  }
};
