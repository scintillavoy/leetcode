#include <algorithm>
#include <deque>
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
  int minimumOperations(TreeNode *root) {
    int num_of_operations = 0;
    deque<pair<TreeNode *, int>> dq;
    dq.push_back({root, 0});
    while (!dq.empty()) {
      sort(dq.begin(), dq.end(),
           [](const pair<TreeNode *, int> a, const pair<TreeNode *, int> b) {
             return a.first->val < b.first->val;
           });
      for (int i = 0; i < dq.size(); ++i) {
        while (dq[i].second != i) {
          ++num_of_operations;
          swap(dq[i], dq[dq[i].second]);
        }
      }
      int index = 0;
      for (int i = dq.size(); i > 0; --i) {
        auto [node, _] = dq.front();
        dq.pop_front();
        if (node->left != nullptr) {
          dq.push_back({node->left, index});
          ++index;
        }
        if (node->right != nullptr) {
          dq.push_back({node->right, index});
          ++index;
        }
      }
    }
    return num_of_operations;
  }
};
