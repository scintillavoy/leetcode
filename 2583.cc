#include <algorithm>
#include <functional>
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
  long long kthLargestLevelSum(TreeNode *root, int k) {
    vector<long long> sums;
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty()) {
      long long sum = 0;
      for (int i = q.size(); i > 0; --i) {
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
      sums.push_back(sum);
    }
    if (k > sums.size()) {
      return -1;
    }
    nth_element(sums.begin(), sums.begin() + k - 1, sums.end(),
                greater<long long>());
    return sums[k - 1];
  }
};
