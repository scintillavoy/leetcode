#include <queue>
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
  bool leafSimilar(TreeNode *root1, TreeNode *root2) {
    traverse1(root1);
    return traverse2(root2) && sequence.empty();
  }

 private:
  queue<int> sequence;

  void traverse1(TreeNode *node) {
    if (node == nullptr) {
      return;
    }
    if (node->left == nullptr && node->right == nullptr) {
      sequence.push(node->val);
      return;
    }
    traverse1(node->left);
    traverse1(node->right);
  }

  bool traverse2(TreeNode *node) {
    if (node == nullptr) {
      return true;
    }
    if (node->left == nullptr && node->right == nullptr) {
      if (sequence.empty() || sequence.front() != node->val) {
        return false;
      }
      sequence.pop();
      return true;
    }
    return traverse2(node->left) && traverse2(node->right);
  }
};
