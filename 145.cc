#include <algorithm>
#include <stack>
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
  vector<int> postorderTraversal(TreeNode *root) {
    if (root == nullptr) {
      return {};
    }
    vector<int> result;
    stack<TreeNode *> stk;
    stk.push(root);
    while (!stk.empty()) {
      TreeNode *curr = stk.top();
      stk.pop();
      result.push_back(curr->val);
      if (curr->left != nullptr) {
        stk.push(curr->left);
      }
      if (curr->right != nullptr) {
        stk.push(curr->right);
      }
    }
    reverse(result.begin(), result.end());
    return result;
  }
};
