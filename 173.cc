#include <stack>
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
class BSTIterator {
 public:
  BSTIterator(TreeNode *root) {
    while (root != nullptr) {
      stk.push(root);
      root = root->left;
    }
  }

  int next() {
    if (stk.empty()) {
      return -1;
    }
    TreeNode *next_node = stk.top();
    stk.pop();
    if (next_node->right != nullptr) {
      TreeNode *temp = next_node->right;
      while (temp != nullptr) {
        stk.push(temp);
        temp = temp->left;
      }
    }
    return next_node->val;
  }

  bool hasNext() { return !stk.empty(); }

 private:
  stack<TreeNode *> stk;
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
