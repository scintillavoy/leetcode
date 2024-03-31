#include <queue>
#include <unordered_set>
#include <utility>
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
  vector<TreeNode *> delNodes(TreeNode *root, vector<int> &to_delete) {
    unordered_set<int> s(to_delete.cbegin(), to_delete.cend());
    vector<TreeNode *> answer;
    queue<pair<TreeNode *, bool>> q;
    TreeNode *dummy = new TreeNode(0, root, nullptr);
    q.push({dummy, true});
    while (!q.empty()) {
      auto [curr, curr_deleted] = q.front();
      q.pop();
      if (curr->left != nullptr) {
        bool child_deleted = s.count(curr->left->val) == 1;
        if (curr_deleted && !child_deleted) {
          answer.push_back(curr->left);
        }
        q.push({curr->left, child_deleted});
        if (child_deleted) {
          curr->left = nullptr;
        }
      }
      if (curr->right != nullptr) {
        bool child_deleted = s.count(curr->right->val) == 1;
        if (curr_deleted && !child_deleted) {
          answer.push_back(curr->right);
        }
        q.push({curr->right, child_deleted});
        if (child_deleted) {
          curr->right = nullptr;
        }
      }
    }
    return answer;
  }
};
