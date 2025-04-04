#include <utility>
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
  TreeNode *lcaDeepestLeaves(TreeNode *root) { return dfs(root).first; }

 private:
  pair<TreeNode *, int> dfs(TreeNode *node) {
    if (node == nullptr) {
      return {nullptr, 0};
    }
    auto left_result = dfs(node->left);
    auto right_result = dfs(node->right);
    if (left_result.second > right_result.second) {
      return {left_result.first, left_result.second + 1};
    }
    if (left_result.second < right_result.second) {
      return {right_result.first, right_result.second + 1};
    }
    return {node, left_result.second + 1};
  }
};
