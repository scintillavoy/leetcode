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
  int countUnivalSubtrees(TreeNode *root) {
    int count = 0;
    count_subtrees(root, count);
    return count;
  }

  bool count_subtrees(TreeNode *node, int &count) {
    if (node == nullptr) {
      return true;
    }
    bool left_is_unival = count_subtrees(node->left, count);
    bool right_is_unival = count_subtrees(node->right, count);
    if (left_is_unival && right_is_unival &&
        (node->left == nullptr || node->left->val == node->val) &&
        (node->right == nullptr || node->right->val == node->val)) {
      ++count;
      return true;
    }
    return false;
  }
};
