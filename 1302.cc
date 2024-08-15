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
  int deepestLeavesSum(TreeNode *root) {
    int max_depth = find_max_depth(root, -1);
    return get_deepest_sum(root, 0, max_depth);
  }

 private:
  int find_max_depth(TreeNode *node, int depth) {
    if (node == nullptr) {
      return depth;
    }
    int left_depth = find_max_depth(node->left, depth + 1);
    int right_depth = find_max_depth(node->right, depth + 1);
    return max(left_depth, right_depth);
  }

  int get_deepest_sum(TreeNode *node, int depth, int max_depth) {
    if (node == nullptr) {
      return 0;
    }
    if (depth == max_depth) {
      return node->val;
    }
    int left_sum = get_deepest_sum(node->left, depth + 1, max_depth);
    int right_sum = get_deepest_sum(node->right, depth + 1, max_depth);
    return left_sum + right_sum;
  }
};
