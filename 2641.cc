#include <deque>
#include <unordered_map>
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
  TreeNode *replaceValueInTree(TreeNode *root) {
    deque<pair<int, TreeNode *>> dq;
    dq.push_back({0, root});
    while (!dq.empty()) {
      int level_sum = 0;
      unordered_map<int, int> sums_by_parent_idx;
      int size = dq.size();
      for (int i = 0; i < size; ++i) {
        auto [parent_idx, node] = dq[i];
        level_sum += node->val;
        sums_by_parent_idx[parent_idx] += node->val;
      }
      for (int i = 0; i < size; ++i) {
        auto [parent_idx, node] = dq.front();
        dq.pop_front();
        node->val = level_sum - sums_by_parent_idx[parent_idx];
        if (node->left != nullptr) {
          dq.push_back({i, node->left});
        }
        if (node->right != nullptr) {
          dq.push_back({i, node->right});
        }
      }
    }
    return root;
  }
};
