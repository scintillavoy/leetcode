#include <vector>
using namespace std;

class Solution {
 public:
  vector<vector<int>> subsets(vector<int>& nums) {
    backtrack(nums, subset, 0);
    return result;
  }

 private:
  vector<vector<int>> result;
  vector<int> subset;

  void backtrack(vector<int>& nums, vector<int>& subset, int index) {
    if (index >= nums.size()) {
      result.push_back(subset);
      return;
    }
    subset.push_back(nums[index]);
    backtrack(nums, subset, index + 1);
    subset.pop_back();
    backtrack(nums, subset, index + 1);
  }
};
