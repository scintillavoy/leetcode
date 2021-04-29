#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  int rob(vector<int>& nums) {
    if (nums.size() == 0) {
      return 0;
    } else if (nums.size() == 1) {
      return nums[0];
    } else if (nums.size() == 2) {
      return max(nums[0], nums[1]);
    }
    vector<int> dp(nums.size());
    dp[0] = nums[0];
    dp[1] = max(dp[0], nums[1]);
    for (vector<int>::size_type i = 2; i < nums.size(); ++i) {
      dp[i] = max(dp[i - 1], nums[i] + dp[i - 2]);
    }
    return dp.back();
  }
};

int main() {
  Solution sol;
  return 0;
}
