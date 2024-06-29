#include <vector>
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
  vector<TreeNode *> splitBST(TreeNode *root, int target) {
    if (root == nullptr) {
      return {nullptr, nullptr};
    }
    if (root->val <= target) {
      vector<TreeNode *> roots = splitBST(root->right, target);
      root->right = roots[0];
      return {root, roots[1]};
    } else {
      vector<TreeNode *> roots = splitBST(root->left, target);
      root->left = roots[1];
      return {roots[0], root};
    }
  }
};

/*
               8
         4           12
      2     6    10      14
    1  3  5  7  9  11  13  15
*/
