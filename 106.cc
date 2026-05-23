#include <unordered_map>
#include <vector>
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
  TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    unordered_map<int, int> val_to_inorder;
    for (int i = 0; i < inorder.size(); ++i) {
      val_to_inorder[inorder[i]] = i;
    }
    return build(inorder, postorder, 0, inorder.size() - 1, 0,
                 postorder.size() - 1, val_to_inorder);
  }

 private:
  TreeNode* build(vector<int>& inorder, vector<int>& postorder,
                  int inorder_start, int inorder_end, int postorder_start,
                  int postorder_end, unordered_map<int, int>& val_to_inorder) {
    if (inorder_start > inorder_end || postorder_start > postorder_end) {
      return nullptr;
    }
    TreeNode* root = new TreeNode(postorder[postorder_end]);
    int inorder_root_index = val_to_inorder[root->val];
    int left_subtree_size = inorder_root_index - inorder_start;
    root->left = build(inorder, postorder, inorder_start,
                       inorder_root_index - 1, postorder_start,
                       postorder_start + left_subtree_size - 1, val_to_inorder);
    root->right = build(inorder, postorder, inorder_root_index + 1, inorder_end,
                        postorder_start + left_subtree_size, postorder_end - 1,
                        val_to_inorder);
    return root;
  }
};
