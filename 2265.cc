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
  int averageOfSubtree(TreeNode *root) {
    traverse(root);
    return answer;
  }

 private:
  int answer = 0;

  pair<int, int> traverse(TreeNode *root) {
    if (root == nullptr) {
      return {0, 0};
    }
    pair<int, int> left_result = traverse(root->left);
    pair<int, int> right_result = traverse(root->right);
    int sum = root->val + left_result.first + right_result.first;
    int count = 1 + left_result.second + right_result.second;
    if (root->val == sum / count) {
      ++answer;
    }
    return {sum, count};
  }
};
