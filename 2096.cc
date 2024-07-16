#include <string>
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
  string getDirections(TreeNode *root, int startValue, int destValue) {
    string start_steps, dest_steps;
    traverse(root, startValue, start_steps);
    traverse(root, destValue, dest_steps);
    int i = 0, j = 0;
    while (i < start_steps.size() && j < dest_steps.size() &&
           start_steps[i] == dest_steps[j]) {
      ++i, ++j;
    }
    string result;
    while (i < start_steps.size()) {
      result.push_back('U');
      ++i;
    }
    while (j < dest_steps.size()) {
      result.push_back(dest_steps[j]);
      ++j;
    }
    return result;
  }

 private:
  bool traverse(TreeNode *node, int value, string &steps) {
    if (node == nullptr) {
      return false;
    }
    if (node->val == value) {
      return true;
    }
    steps.push_back('L');
    if (traverse(node->left, value, steps)) {
      return true;
    }
    steps.pop_back();
    steps.push_back('R');
    if (traverse(node->right, value, steps)) {
      return true;
    }
    steps.pop_back();
    return false;
  }
};
