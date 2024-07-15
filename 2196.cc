#include <unordered_map>
#include <unordered_set>
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
  TreeNode *createBinaryTree(vector<vector<int>> &descriptions) {
    for (const auto &description : descriptions) {
      TreeNode *parent, *child;
      if (value_to_node.count(description[0]) == 0) {
        parent = new TreeNode(description[0]);
        value_to_node[description[0]] = parent;
      } else {
        parent = value_to_node[description[0]];
      }
      if (value_to_node.count(description[1]) == 0) {
        child = new TreeNode(description[1]);
        value_to_node[description[1]] = child;
      } else {
        child = value_to_node[description[1]];
      }
      non_root_values.insert(description[1]);
      if (description[2] == 1) {
        parent->left = child;
      } else {
        parent->right = child;
      }
    }
    for (const auto [value, node] : value_to_node) {
      if (non_root_values.count(value) == 0) {
        return node;
      }
    }
    return nullptr;
  }

 private:
  unordered_map<int, TreeNode *> value_to_node;
  unordered_set<int> non_root_values;
};
