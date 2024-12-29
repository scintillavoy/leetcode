#include <algorithm>
#include <vector>
using namespace std;

class Solution {
 public:
  int maxSumAfterOperation(vector<int>& nums) {
    vector<int> dp = {nums[0], nums[0] * nums[0]};
    int max_sum = dp[1];
    for (int i = 1; i < nums.size(); ++i) {
      dp = {
          max(dp[0] + nums[i], nums[i]),
          max({dp[0] + nums[i] * nums[i], dp[1] + nums[i], nums[i] * nums[i]})};
      max_sum = max({max_sum, dp[0], dp[1]});
    }
    return max_sum;
  }
};
