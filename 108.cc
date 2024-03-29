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
  TreeNode *sortedArrayToBST(vector<int> &nums) {
    return convert(nums, 0, nums.size() - 1);
  }

 private:
  TreeNode *convert(vector<int> &nums, int start, int end) {
    if (start > end) {
      return nullptr;
    }
    int mid = (start + end) / 2;
    TreeNode *left = convert(nums, start, mid - 1);
    TreeNode *right = convert(nums, mid + 1, end);
    return new TreeNode(nums[mid], left, right);
  }
};
