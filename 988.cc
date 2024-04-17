#include <deque>
#include <string>
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
  string smallestFromLeaf(TreeNode *root) {
    traverse(root);
    return string(answer.cbegin(), answer.cend());
  }

 private:
  deque<char> str;
  deque<char> answer;

  void traverse(TreeNode *curr) {
    if (curr == nullptr) {
      return;
    }
    str.push_front(curr->val + 'a');
    if (curr->left == nullptr && curr->right == nullptr) {
      if (answer.empty() || answer > str) {
        answer = str;
      }
    } else {
      traverse(curr->left);
      traverse(curr->right);
    }
    str.pop_front();
  }
};
