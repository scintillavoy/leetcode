#include <queue>
#include <unordered_set>
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
class FindElements {
 public:
  FindElements(TreeNode *root) {
    queue<TreeNode *> q;
    if (root != nullptr) {
      root->val = 0;
      q.push(root);
    }
    while (!q.empty()) {
      TreeNode *node = q.front();
      q.pop();
      elements.insert(node->val);
      if (node->left != nullptr) {
        node->left->val = 2 * node->val + 1;
        q.push(node->left);
      }
      if (node->right != nullptr) {
        node->right->val = 2 * node->val + 2;
        q.push(node->right);
      }
    }
  }

  bool find(int target) { return elements.contains(target); }

 private:
  unordered_set<int> elements;
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */
