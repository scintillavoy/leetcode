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
  bool isSymmetric(TreeNode* root) {
    return check_symmetry(root->left, root->right);
  }

 private:
  bool check_symmetry(TreeNode* left, TreeNode* right) {
    if (left == nullptr && right == nullptr) {
      return true;
    }
    if (left == nullptr) {
      return false;
    }
    if (right == nullptr) {
      return false;
    }
    if (left->val != right->val) {
      return false;
    }
    return check_symmetry(left->left, right->right) &&
           check_symmetry(left->right, right->left);
  }
};
