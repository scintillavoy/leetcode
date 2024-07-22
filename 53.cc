#include <algorithm>
#include <limits>
#include <vector>
using namespace std;

class Solution {
 public:
  int maxSubArray(vector<int>& nums) {
    int left = 0, right = 0;
    int max_sum = numeric_limits<int>::min();
    int sum = 0;
    while (right < nums.size()) {
      sum += nums[right];
      ++right;
      while (sum < 0) {
        sum -= nums[left];
        ++left;
      }
      if (left < right) {
        max_sum = max(max_sum, sum);
      }
    }
    if (max_sum == numeric_limits<int>::min()) {
      max_sum = *max_element(nums.cbegin(), nums.cend());
    }
    return max_sum;
  }
};
