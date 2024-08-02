#include <algorithm>
#include <vector>
using namespace std;

class Solution {
 public:
  int minSwaps(vector<int>& nums) {
    int total_ones = 0;
    for (const auto num : nums) {
      if (num == 1) {
        ++total_ones;
      }
    }
    int start = 0, end = total_ones - 1;
    int curr_ones = 0;
    for (int i = start; i <= end; ++i) {
      if (nums[i] == 1) {
        ++curr_ones;
      }
    }
    int min_swaps = total_ones - curr_ones;
    while (start < nums.size()) {
      if (nums[start] == 1) {
        --curr_ones;
      }
      ++start;
      end = (end + 1) % nums.size();
      if (nums[end] == 1) {
        ++curr_ones;
      }
      min_swaps = min(min_swaps, total_ones - curr_ones);
    }
    return min_swaps;
  }
};
