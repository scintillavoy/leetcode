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
  int sumNumbers(TreeNode *root) { return traverse(root, 0); }

  int traverse(TreeNode *curr, int parent_num) {
    if (curr == nullptr) {
      return 0;
    }
    int num = parent_num * 10 + curr->val;
    if (curr->left == nullptr && curr->right == nullptr) {
      return num;
    }
    return traverse(curr->left, num) + traverse(curr->right, num);
  }
};
