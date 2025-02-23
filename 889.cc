#include <stack>
#include <unordered_map>
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
  TreeNode *constructFromPrePost(vector<int> &preorder,
                                 vector<int> &postorder) {
    unordered_map<int, int> val_to_postorder_index;
    for (int i = 0; i < postorder.size(); ++i) {
      val_to_postorder_index[postorder[i]] = i;
    }
    TreeNode *root = new TreeNode(preorder[0]);
    stack<TreeNode *> stk;
    stk.push(root);
    for (int i = 1; i < preorder.size(); ++i) {
      while (val_to_postorder_index[preorder[i]] >
             val_to_postorder_index[stk.top()->val]) {
        stk.pop();
      }
      TreeNode *parent = stk.top();
      TreeNode *node = new TreeNode(preorder[i]);
      stk.push(node);
      if (parent->left == nullptr) {
        parent->left = node;
      } else {
        parent->right = node;
      }
    }
    return root;
  }
};
