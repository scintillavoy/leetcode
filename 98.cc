struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode* left, TreeNode* right)
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
  bool isValidBST(TreeNode* root) {
    if (root == nullptr) {
      return true;
    }
    return traverse(root->left, nullptr, root) &&
           traverse(root->right, root, nullptr);
  }

 private:
  bool traverse(TreeNode* node, TreeNode* low, TreeNode* high) {
    if (node == nullptr) {
      return true;
    }
    if (low != nullptr && node->val <= low->val) {
      return false;
    }
    if (high != nullptr && node->val >= high->val) {
      return false;
    }
    return traverse(node->left, low, node) && traverse(node->right, node, high);
  }
};
