#include <vector>
using namespace std;

class Solution {
 public:
  vector<int> applyOperations(vector<int>& nums) {
    for (int i = 1; i < nums.size(); ++i) {
      if (nums[i - 1] == nums[i]) {
        nums[i - 1] *= 2;
        nums[i] = 0;
      }
    }
    int next_nonzero_index = 0;
    for (int i = 0; i < nums.size(); ++i) {
      if (nums[i] != 0) {
        nums[next_nonzero_index] = nums[i];
        ++next_nonzero_index;
      }
    }
    for (int i = next_nonzero_index; i < nums.size(); ++i) {
      nums[i] = 0;
    }
    return nums;
  }
};
