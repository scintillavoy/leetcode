#include <vector>
using namespace std;

class Solution {
 public:
  int pathSum(vector<int> &nums) {
    vector<vector<int>> tree(5, vector<int>(16, -1));
    for (const auto num : nums) {
      tree[num / 100 - 1][num / 10 % 10 - 1] = num % 10;
    }
    return dfs(tree, 0, 0, 0);
  }

 private:
  int dfs(const vector<vector<int>> &tree, int curr_sum, int depth, int index) {
    if (tree[depth][index] == -1) {
      return 0;
    }
    curr_sum += tree[depth][index];
    int left_index = index * 2;
    int right_index = left_index + 1;
    if (tree[depth + 1][left_index] == -1 &&
        tree[depth + 1][right_index] == -1) {
      return curr_sum;
    }
    return dfs(tree, curr_sum, depth + 1, left_index) +
           dfs(tree, curr_sum, depth + 1, right_index);
  }
};
