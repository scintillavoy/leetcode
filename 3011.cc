#include <algorithm>
#include <limits>
#include <vector>
using namespace std;

class Solution {
 public:
  bool canSortArray(vector<int>& nums) {
    int prev_max = numeric_limits<int>::min();
    int curr_max = numeric_limits<int>::min();
    int curr_min = numeric_limits<int>::max();
    int start = 0;
    for (int end = 0; end < nums.size(); ++end) {
      if (count_set_bits(nums[start]) != count_set_bits(nums[end])) {
        prev_max = curr_max;
        curr_max = nums[end];
        curr_min = nums[end];
        start = end;
      } else {
        curr_max = max(curr_max, nums[end]);
        curr_min = min(curr_min, nums[end]);
      }
      if (prev_max > curr_min) {
        return false;
      }
    }
    return true;
  }

 private:
  int count_set_bits(int num) {
    int count = 0;
    while (num > 0) {
      if (num & 1 == 1) {
        ++count;
      }
      num >>= 1;
    }
    return count;
  }
};
