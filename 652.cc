#include <string>
#include <unordered_map>
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
  vector<TreeNode *> findDuplicateSubtrees(TreeNode *root) {
    unordered_map<string, TreeNode *> structure_to_root;
    traverse(root, structure_to_root);
    vector<TreeNode *> result;
    for (const auto &[structure, root] : structure_to_root) {
      if (root != nullptr) {
        result.push_back(root);
      }
    }
    return result;
  }

 private:
  string traverse(TreeNode *node,
                  unordered_map<string, TreeNode *> &structure_to_root) {
    if (node == nullptr) {
      return "";
    }
    string structure = to_string(node->val) + '|' +
                       traverse(node->left, structure_to_root) + '|' +
                       traverse(node->right, structure_to_root);
    if (structure_to_root.contains(structure)) {
      structure_to_root[structure] = node;
    } else {
      structure_to_root[structure] = nullptr;
    }
    return structure;
  }
};
