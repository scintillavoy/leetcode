#include <algorithm>
#include <vector>
using namespace std;

class Solution {
 public:
  int rob(vector<int>& nums) {
    int n = nums.size();
    if (n < 2) {
      return nums[0];
    }
    // dp[0][*]: rob nums[0]
    // dp[1][*]: do not rob nums[0]
    // dp[*][0]: previous
    // dp[*][1]: current
    vector<vector<int>> dp(2, vector<int>(2));
    dp[0] = {nums[0], nums[0]};
    dp[1] = {0, nums[1]};
    for (int i = 2; i < n - 1; ++i) {
      for (int j = 0; j < 2; ++j) {
        dp[j] = {dp[j][1], max(dp[j][1], dp[j][0] + nums[i])};
      }
    }
    dp[1][1] = max(dp[1][1], dp[1][0] + nums[n - 1]);
    return max(dp[0][1], dp[1][1]);
  }
};
