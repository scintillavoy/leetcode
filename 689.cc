#include <utility>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
    int n = nums.size();
    vector<int> sums(n);
    int sum = 0;
    for (int i = 0; i < k - 1; ++i) {
      sum += nums[i];
    }
    int left = 0;
    for (int right = k - 1; right < n; ++right) {
      sum += nums[right];
      sums[right] = sum;
      sum -= nums[left];
      ++left;
    }
    vector<vector<pair<int, int>>> dp(4, vector<pair<int, int>>(n + 1));
    for (int i = 1; i <= 3; ++i) {
      for (int j = i * k; j <= n; ++j) {
        int sum = sums[j - 1] + dp[i - 1][j - k].first;
        if (sum > dp[i][j - 1].first) {
          dp[i][j] = {sum, j - k};
        } else {
          dp[i][j] = dp[i][j - 1];
        }
      }
    }
    vector<int> result(3);
    int current_end = n;
    for (int i = 3; i >= 1; --i) {
      result[i - 1] = dp[i][current_end].second;
      current_end = result[i - 1];
    }
    return result;
  }
};
