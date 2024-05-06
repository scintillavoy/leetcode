#include <algorithm>
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
  int closestValue(TreeNode *root, double target) {
    int answer = root->val;
    while (root != nullptr) {
      if (abs(root->val - target) < abs(answer - target)) {
        answer = root->val;
      } else if (abs(root->val - target) == abs(answer - target)) {
        answer = min(root->val, answer);
      }
      if (root->val < target) {
        root = root->right;
      } else {
        root = root->left;
      }
    }
    return answer;
  }
};
