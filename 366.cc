#include <algorithm>
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
  vector<vector<int>> findLeaves(TreeNode *root) {
    postorder(root);
    return answer;
  }

 private:
  vector<vector<int>> answer;

  int postorder(TreeNode *curr) {
    if (curr == nullptr) {
      return -1;
    }
    int left = postorder(curr->left);
    int right = postorder(curr->right);
    int height = max(left, right) + 1;
    while (answer.size() <= height) {
      answer.push_back(vector<int>());
    }
    answer[height].push_back(curr->val);
    return height;
  }
};
