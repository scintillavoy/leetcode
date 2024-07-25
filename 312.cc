#include <algorithm>
#include <vector>
using namespace std;

class Solution {
 public:
  int maxCoins(vector<int>& nums) {
    nums.insert(nums.begin(), 1);
    nums.push_back(1);
    int n = nums.size();
    vector<vector<int>> dp(n, vector<int>(n));
    for (int len = 1; len <= n - 2; ++len) {
      for (int left = 1; left <= n - 1 - len; ++left) {
        int right = left + len - 1;
        for (int j = left; j <= right; ++j) {
          int gain = nums[left - 1] * nums[j] * nums[right + 1];
          int remaining = dp[left][j - 1] + dp[j + 1][right];
          dp[left][right] = max(dp[left][right], gain + remaining);
        }
      }
    }
    return dp[1][n - 2];
  }
};
