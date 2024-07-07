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
  int maxDepth(TreeNode *root) {
    int max_height = 0;
    traverse(root, 1, max_height);
    return max_height;
  }

 private:
  void traverse(TreeNode *node, int height, int &max_height) {
    if (node == nullptr) {
      return;
    }
    max_height = max(max_height, height);
    traverse(node->left, height + 1, max_height);
    traverse(node->right, height + 1, max_height);
  }
};
