#include <stack>
#include <string>
#include <utility>
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
  TreeNode *recoverFromPreorder(string traversal) {
    stack<TreeNode *> stk;
    TreeNode *dummy_node = new TreeNode();
    stk.push(dummy_node);
    int index = 0;
    while (index < traversal.size()) {
      auto [depth, val] = parse_depth_and_val(traversal, index);
      while (depth + 1 < stk.size()) {
        stk.pop();
      }
      TreeNode *parent = stk.top();
      TreeNode *curr_node = new TreeNode(val);
      stk.push(curr_node);
      if (parent->left == nullptr) {
        parent->left = curr_node;
      } else {
        parent->right = curr_node;
      }
    }
    TreeNode *root = dummy_node->left;
    delete dummy_node;
    return root;
  }

 private:
  pair<int, int> parse_depth_and_val(const string &traversal, int &index) {
    int depth = 0;
    int val = 0;
    while (index < traversal.size() && traversal[index] == '-') {
      ++depth;
      ++index;
    }
    while (index < traversal.size() && traversal[index] != '-') {
      val = val * 10 + traversal[index] - '0';
      ++index;
    }
    return {depth, val};
  }
};
