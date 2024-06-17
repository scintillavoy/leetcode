#include <utility>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<vector<int>> permute(vector<int> &nums) {
    vector<vector<int>> result;
    vector<int> curr;
    backtrack(result, nums, curr, 0);
    return result;
  }

 private:
  void backtrack(vector<vector<int>> &result, vector<int> &nums,
                 vector<int> &curr, int depth) {
    if (curr.size() == nums.size()) {
      result.push_back(curr);
      return;
    }
    for (int i = depth; i < nums.size(); ++i) {
      swap(nums[depth], nums[i]);
      curr.push_back(nums[depth]);
      backtrack(result, nums, curr, depth + 1);
      curr.pop_back();
      swap(nums[depth], nums[i]);
    }
  }
};
