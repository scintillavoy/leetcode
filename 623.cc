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
  TreeNode *addOneRow(TreeNode *root, int val, int depth) {
    if (depth == 1) {
      return new TreeNode(val, root, nullptr);
    }
    traverse(root, val, depth, 1);
    return root;
  }

  void traverse(TreeNode *node, int val, int depth, int curr_depth) {
    if (node == nullptr) {
      return;
    }
    if (curr_depth == depth - 1) {
      TreeNode *left = node->left;
      TreeNode *right = node->right;
      node->left = new TreeNode(val, left, nullptr);
      node->right = new TreeNode(val, nullptr, right);
      return;
    }
    traverse(node->left, val, depth, curr_depth + 1);
    traverse(node->right, val, depth, curr_depth + 1);
  }
};
