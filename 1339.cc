#include <algorithm>
using namespace std;

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode* left, TreeNode* right)
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
  int maxProduct(TreeNode* root) {
    int total_sum = get_sum(root);
    long long max_product = 0;
    get_max_product(root, total_sum, max_product);
    return max_product % 1'000'000'007;
  }

 private:
  int get_sum(TreeNode* node) {
    if (node == nullptr) {
      return 0;
    }
    return get_sum(node->left) + node->val + get_sum(node->right);
  }

  int get_max_product(TreeNode* node, int total_sum, long long& max_product) {
    if (node == nullptr) {
      return 0;
    }
    int sum = get_max_product(node->left, total_sum, max_product) + node->val +
              get_max_product(node->right, total_sum, max_product);
    max_product = max(max_product, (long long)(total_sum - sum) * sum);
    return sum;
  }
};
