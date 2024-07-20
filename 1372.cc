#include <algorithm>
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
  int longestZigZag(TreeNode *root) { return traverse(root, 0, 0); }

 private:
  int traverse(TreeNode *node, int left_length, int right_length) {
    if (node == nullptr) {
      return max(left_length, right_length) - 1;
    }
    int left_result = traverse(node->left, right_length + 1, 0);
    int right_result = traverse(node->right, 0, left_length + 1);
    return max(left_result, right_result);
  }
};
