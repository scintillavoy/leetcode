#include <algorithm>
#include <unordered_map>
#include <utility>
#include <vector>
using namespace std;

#define MAX 100'000 + 1

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
  vector<int> treeQueries(TreeNode *root, vector<int> &queries) {
    vector<int> depth_by_val(MAX);
    vector<int> height_by_val(MAX);
    vector<pair<int, int>> top_heights_by_depth(MAX);
    int root_height =
        find_height(root, 0, depth_by_val, height_by_val, top_heights_by_depth);
    vector<int> results;
    for (const auto query : queries) {
      if (height_by_val[query] ==
          top_heights_by_depth[depth_by_val[query]].first) {
        results.push_back(root_height - 1 -
                          (height_by_val[query] -
                           top_heights_by_depth[depth_by_val[query]].second));
      } else {
        results.push_back(root_height - 1);
      }
    }
    return results;
  }

 private:
  int find_height(TreeNode *node, int depth, vector<int> &depth_by_val,
                  vector<int> &height_by_val,
                  vector<pair<int, int>> &top_heights_by_depth) {
    if (node == nullptr) {
      return 0;
    }
    depth_by_val[node->val] = depth;
    height_by_val[node->val] =
        1 + max(find_height(node->left, depth + 1, depth_by_val, height_by_val,
                            top_heights_by_depth),
                find_height(node->right, depth + 1, depth_by_val, height_by_val,
                            top_heights_by_depth));
    if (top_heights_by_depth[depth].first <= height_by_val[node->val]) {
      top_heights_by_depth[depth] = {height_by_val[node->val],
                                     top_heights_by_depth[depth].first};
    } else if (top_heights_by_depth[depth].second <= height_by_val[node->val]) {
      top_heights_by_depth[depth] = {top_heights_by_depth[depth].first,
                                     height_by_val[node->val]};
    }
    return height_by_val[node->val];
  }
};
