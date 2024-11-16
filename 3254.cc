#include <vector>
using namespace std;

class Solution {
 public:
  vector<int> resultsArray(vector<int>& nums, int k) {
    if (k == 1) {
      return nums;
    }
    vector<int> result;
    int consecutive_count = 1;
    int right = 0;
    for (int left = 0; left < nums.size() - k + 1; ++left) {
      if (left > 0) {
        if (nums[left - 1] + 1 == nums[left]) {
          --consecutive_count;
        }
      }
      while (right - left + 1 < k) {
        ++right;
        if (nums[right - 1] + 1 == nums[right]) {
          ++consecutive_count;
        }
      }
      if (consecutive_count == k) {
        result.push_back(nums[right]);
      } else {
        result.push_back(-1);
      }
    }
    return result;
  }
};
