#include <unordered_map>
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
  int countPairs(TreeNode *root, int distance) {
    this->total_count = 0;
    this->distance = distance;
    traverse(root, 0);
    return total_count;
  }

 private:
  int distance;
  int total_count;

  unordered_map<int, int> traverse(TreeNode *node, int depth) {
    unordered_map<int, int> result;
    if (node == nullptr) {
      return result;
    }
    if (node->left == nullptr && node->right == nullptr) {
      ++result[depth];
      return result;
    }
    unordered_map<int, int> left_result = traverse(node->left, depth + 1);
    unordered_map<int, int> right_result = traverse(node->right, depth + 1);
    for (const auto [left_depth, left_count] : left_result) {
      if (left_depth - depth >= distance) {
        continue;
      }
      for (const auto [right_depth, right_count] : right_result) {
        if (left_depth + right_depth - depth * 2 <= distance) {
          total_count += left_count * right_count;
        }
      }
    }
    for (const auto [left_depth, left_count] : left_result) {
      if (left_depth - depth < distance) {
        result[left_depth] += left_count;
      }
    }
    for (const auto [right_depth, right_count] : right_result) {
      if (right_depth - depth < distance) {
        result[right_depth] += right_count;
      }
    }
    return result;
  }
};
