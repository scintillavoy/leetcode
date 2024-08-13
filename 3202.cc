#include <algorithm>
#include <vector>
using namespace std;

class Solution {
 public:
  int maximumLength(vector<int>& nums, int k) {
    int max_length = 1;
    vector<vector<int>> dp(nums.size(), vector<int>(k, 1));
    for (int i = 1; i < nums.size(); ++i) {
      for (int j = 0; j < i; ++j) {
        int remainder = (nums[i] + nums[j]) % k;
        dp[i][remainder] = dp[j][remainder] + 1;
        max_length = max(max_length, dp[i][remainder]);
      }
    }
    return max_length;
  }
};
