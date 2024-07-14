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
  int goodNodes(TreeNode *root) { return traverse(root, root->val); }

 private:
  int traverse(TreeNode *node, int max_value) {
    if (node == nullptr) {
      return 0;
    }
    int result = 0;
    if (node->val >= max_value) {
      ++result;
      max_value = node->val;
    }
    result +=
        traverse(node->left, max_value) + traverse(node->right, max_value);
    return result;
  }
};
