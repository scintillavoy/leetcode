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
  TreeNode *deleteNode(TreeNode *root, int key) {
    TreeNode *parent = nullptr;
    TreeNode *curr = root;
    while (curr != nullptr) {
      if (curr->val > key) {
        parent = curr;
        curr = curr->left;
      } else if (curr->val < key) {
        parent = curr;
        curr = curr->right;
      } else {
        break;
      }
    }
    if (curr == nullptr) {
      return root;
    }
    TreeNode *new_child = nullptr;
    if (curr->left != nullptr) {
      TreeNode *predecessor = curr->left;
      while (predecessor->right != nullptr) {
        predecessor = predecessor->right;
      }
      predecessor->right = curr->right;
      new_child = curr->left;
    } else {
      new_child = curr->right;
    }
    if (parent != nullptr) {
      if (parent->left == curr) {
        parent->left = new_child;
      } else {
        parent->right = new_child;
      }
    } else {
      root = new_child;
    }
    return root;
  }
};
