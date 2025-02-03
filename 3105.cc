#include <algorithm>
#include <vector>
using namespace std;

class Solution {
 public:
  int longestMonotonicSubarray(vector<int>& nums) {
    int max_length = 1;
    int inc_left = 0;
    int dec_left = 0;
    for (int right = 1; right < nums.size(); ++right) {
      if (nums[right - 1] >= nums[right]) {
        inc_left = right;
      }
      max_length = max(max_length, right - inc_left + 1);
      if (nums[right - 1] <= nums[right]) {
        dec_left = right;
      }
      max_length = max(max_length, right - dec_left + 1);
    }
    return max_length;
  }
};
