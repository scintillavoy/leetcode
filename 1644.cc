#define NULL nullptr

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
 public:
  TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    TreeNode* lca = find_lca(root, p, q);
    if (found_p && found_q) {
      return lca;
    }
    return nullptr;
  }

 private:
  bool found_p = false;
  bool found_q = false;

  TreeNode* find_lca(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (root == nullptr) {
      return root;
    }
    TreeNode* left = find_lca(root->left, p, q);
    TreeNode* right = find_lca(root->right, p, q);
    if (root == p) {
      found_p = true;
      return root;
    }
    if (root == q) {
      found_q = true;
      return root;
    }
    if (left != nullptr && right != nullptr) {
      return root;
    }
    if (left != nullptr) {
      return left;
    }
    return right;
  }
};
