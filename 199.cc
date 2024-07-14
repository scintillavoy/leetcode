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
  vector<int> rightSideView(TreeNode *root) {
    vector<int> result;
    traverse(root, 0, result);
    return result;
  }

 private:
  void traverse(TreeNode *node, int depth, vector<int> &result) {
    if (node == nullptr) {
      return;
    }
    if (depth >= result.size()) {
      result.push_back(node->val);
    }
    traverse(node->right, depth + 1, result);
    traverse(node->left, depth + 1, result);
  }
};
