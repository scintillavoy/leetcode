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
  TreeNode *bstToGst(TreeNode *root) {
    traverse(root, 0);
    return root;
  }

 private:
  int traverse(TreeNode *curr, int sum) {
    if (curr == nullptr) {
      return 0;
    }
    int right_sum = traverse(curr->right, sum);
    int curr_val = curr->val;
    curr->val += sum + right_sum;
    int left_sum = traverse(curr->left, curr->val);
    return left_sum + curr_val + right_sum;
  }
};
