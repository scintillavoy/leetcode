#include <algorithm>
#include <vector>
using namespace std;

class Solution {
 public:
  int longestArithSeqLength(vector<int>& nums) {
    int max_length = 1;
    vector<vector<int>> dp(nums.size(), vector<int>(1001, 1));
    for (int i = 1; i < nums.size(); ++i) {
      for (int j = 0; j < i; ++j) {
        int diff = nums[i] - nums[j] + 500;
        dp[i][diff] = dp[j][diff] + 1;
        max_length = max(max_length, dp[i][diff]);
      }
    }
    return max_length;
  }
};
