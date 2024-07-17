#include <algorithm>
#include <limits>
#include <queue>
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
  int maxLevelSum(TreeNode *root) {
    int max_sum = numeric_limits<int>::min();
    int max_level = 0;
    queue<TreeNode *> q;
    q.push(root);
    int curr_level = 1;
    while (!q.empty()) {
      int sum = 0;
      int size = q.size();
      for (int i = 0; i < size; ++i) {
        TreeNode *curr = q.front();
        q.pop();
        sum += curr->val;
        if (curr->left != nullptr) {
          q.push(curr->left);
        }
        if (curr->right != nullptr) {
          q.push(curr->right);
        }
      }
      if (max_sum < sum) {
        max_sum = sum;
        max_level = curr_level;
      }
      ++curr_level;
    }
    return max_level;
  }
};
