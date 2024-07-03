#include <algorithm>
#include <functional>
#include <limits>
#include <vector>
using namespace std;

class Solution {
 public:
  int minDifference(vector<int>& nums) {
    if (nums.size() <= 4) {
      return 0;
    }
    partial_sort(nums.begin(), nums.begin() + 4, nums.end());
    partial_sort(nums.rbegin(), nums.rbegin() + 4, nums.rend(), greater<int>());
    int result = numeric_limits<int>::max();
    for (int i = 0; i < 4; ++i) {
      result = min(result, nums[nums.size() - 4 + i] - nums[i]);
    }
    return result;
  }
};
