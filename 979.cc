#include <cmath>
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
  int distributeCoins(TreeNode *root) {
    moves = 0;
    traverse(root);
    return moves;
  }

 private:
  int moves;

  int traverse(TreeNode *root) {
    if (root == nullptr) {
      return 0;
    }
    int left_coins = traverse(root->left);
    int right_coins = traverse(root->right);
    moves += abs(left_coins) + abs(right_coins);
    return left_coins + right_coins + root->val - 1;
  }
};
