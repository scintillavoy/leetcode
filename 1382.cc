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
  TreeNode *balanceBST(TreeNode *root) {
    add_to_vector(root);
    return make_tree(0, values.size());
  }

 private:
  vector<int> values;

  void add_to_vector(TreeNode *node) {
    if (node == nullptr) {
      return;
    }
    add_to_vector(node->left);
    values.push_back(node->val);
    add_to_vector(node->right);
  }

  TreeNode *make_tree(int start, int end) {
    if (start >= end) {
      return nullptr;
    }
    int mid = (start + end) / 2;
    TreeNode *left = make_tree(start, mid);
    TreeNode *right = make_tree(mid + 1, end);
    return new TreeNode(values[mid], left, right);
  }
};
