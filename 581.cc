#include <algorithm>
#include <vector>
using namespace std;

class Solution {
 public:
  int findUnsortedSubarray(vector<int>& nums) {
    int left = -1;
    int right = -1;
    for (int i = 1; i < nums.size(); ++i) {
      if (nums[i - 1] > nums[i]) {
        if (left == -1) {
          left = i - 1;
        }
        right = i;
      }
    }
    if (left == -1) {
      return 0;
    }
    int max_in_range = nums[left];
    int min_in_range = nums[left];
    for (int i = left; i <= right; ++i) {
      max_in_range = max(max_in_range, nums[i]);
      min_in_range = min(min_in_range, nums[i]);
    }
    while (left - 1 >= 0 && nums[left - 1] > min_in_range) {
      --left;
    }
    while (right + 1 < nums.size() && nums[right + 1] < max_in_range) {
      ++right;
    }
    return right - left + 1;
  }
};
