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
  int pathSum(TreeNode *root, int targetSum) {
    unordered_map<long long, int> counts{{0, 1}};
    return traverse(root, targetSum, 0, counts);
  }

 private:
  int traverse(TreeNode *node, int target_sum, long long prefix_sum,
               unordered_map<long long, int> &counts) {
    if (node == nullptr) {
      return 0;
    }
    prefix_sum += node->val;
    int count = counts[prefix_sum - target_sum];
    ++counts[prefix_sum];
    int left_result = traverse(node->left, target_sum, prefix_sum, counts);
    int right_result = traverse(node->right, target_sum, prefix_sum, counts);
    --counts[prefix_sum];
    return count + left_result + right_result;
  }
};
