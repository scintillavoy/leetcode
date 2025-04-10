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
  int minCameraCover(TreeNode *root) {
    CoverResult cover_result = cover(root);
    return cover_result.num_of_cameras + (cover_result.covered ? 0 : 1);
  }

 private:
  struct CoverResult {
    int num_of_cameras;
    bool covered;
    bool installed;
  };

  CoverResult cover(TreeNode *node) {
    if (node == nullptr) {
      return {0, true, false};
    }
    CoverResult left_result = cover(node->left);
    CoverResult right_result = cover(node->right);
    if (!left_result.covered || !right_result.covered) {
      return {
          left_result.num_of_cameras + right_result.num_of_cameras + 1,
          true,
          true,
      };
    }
    return {
        left_result.num_of_cameras + right_result.num_of_cameras,
        left_result.installed || right_result.installed,
        false,
    };
  }
};
