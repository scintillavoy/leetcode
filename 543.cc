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
  int diameterOfBinaryTree(TreeNode *root) {
    diameter = 0;
    find_diameter(root);
    return diameter;
  }

 private:
  int diameter;

  int find_diameter(TreeNode *node) {
    if (node == nullptr) {
      return 0;
    }
    int left_height = find_diameter(node->left);
    int right_height = find_diameter(node->right);
    diameter = max(diameter, left_height + right_height);
    return max(left_height, right_height) + 1;
  }
};
