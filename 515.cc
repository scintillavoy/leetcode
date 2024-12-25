#include <algorithm>
#include <limits>
#include <queue>
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
  vector<int> largestValues(TreeNode *root) {
    vector<int> largest_values;
    queue<TreeNode *> q;
    if (root != nullptr) {
      q.push(root);
    }
    while (!q.empty()) {
      int largest_value = numeric_limits<int>::min();
      for (int i = q.size(); i > 0; --i) {
        TreeNode *curr = q.front();
        q.pop();
        largest_value = max(largest_value, curr->val);
        if (curr->left != nullptr) {
          q.push(curr->left);
        }
        if (curr->right != nullptr) {
          q.push(curr->right);
        }
      }
      largest_values.push_back(largest_value);
    }
    return largest_values;
  }
};
