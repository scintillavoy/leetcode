#include <algorithm>
#include <limits>
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
  int maxPathSum(TreeNode *root) {
    max_sum = numeric_limits<int>::min();
    find_max_sum(root);
    return max_sum;
  }

 private:
  int max_sum;

  int find_max_sum(TreeNode *root) {
    if (root == nullptr) {
      return 0;
    }
    int curr_max_sum = root->val;
    int left_max_sum = find_max_sum(root->left);
    if (left_max_sum > 0) {
      curr_max_sum += left_max_sum;
    }
    int right_max_sum = find_max_sum(root->right);
    if (right_max_sum > 0) {
      curr_max_sum += right_max_sum;
    }
    max_sum = max(max_sum, curr_max_sum);
    return max({left_max_sum, right_max_sum, 0}) + root->val;
  }
};
