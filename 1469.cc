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
  vector<int> getLonelyNodes(TreeNode *root) {
    vector<int> lonely_nodes;
    traverse(root, lonely_nodes);
    return lonely_nodes;
  }

  void traverse(TreeNode *curr, vector<int> &lonely_nodes) {
    if (curr == nullptr) {
      return;
    }
    if (curr->left != nullptr && curr->right == nullptr) {
      lonely_nodes.push_back(curr->left->val);
    } else if (curr->left == nullptr && curr->right != nullptr) {
      lonely_nodes.push_back(curr->right->val);
    }
    traverse(curr->left, lonely_nodes);
    traverse(curr->right, lonely_nodes);
  }
};
