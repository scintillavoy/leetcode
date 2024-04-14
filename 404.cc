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
  int sumOfLeftLeaves(TreeNode *root) { return preorder(root, false); }

 private:
  int preorder(TreeNode *curr, bool is_left) {
    if (curr == nullptr) {
      return 0;
    }
    if (is_left && curr->left == nullptr && curr->right == nullptr) {
      return curr->val;
    }
    int left = preorder(curr->left, true);
    int right = preorder(curr->right, false);
    return left + right;
  }
};
