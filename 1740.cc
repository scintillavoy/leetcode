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
  int findDistance(TreeNode *root, int p, int q) {
    vector<bool> p_path, q_path;
    find_path(root, p, p_path);
    find_path(root, q, q_path);
    int i = 0, j = 0;
    while (i < p_path.size() && j < q_path.size() && p_path[i] == q_path[j]) {
      ++i, ++j;
    }
    return p_path.size() - i + q_path.size() - j;
  }

 private:
  bool find_path(TreeNode *node, int target, vector<bool> &path) {
    if (node == nullptr) {
      return false;
    }
    if (node->val == target) {
      return true;
    }
    path.push_back(false);
    if (find_path(node->left, target, path)) {
      return true;
    }
    path.pop_back();
    path.push_back(true);
    if (find_path(node->right, target, path)) {
      return true;
    }
    path.pop_back();
    return false;
  }
};
