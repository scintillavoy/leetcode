#include <vector>
using namespace std;

class Solution {
 public:
  int subsetXORSum(vector<int>& nums) { return backtrack(nums, 0, 0); }

 private:
  int backtrack(vector<int>& nums, int depth, int value) {
    if (depth == nums.size()) {
      return value;
    }
    return backtrack(nums, depth + 1, value) +
           backtrack(nums, depth + 1, value ^ nums[depth]);
  }
};
