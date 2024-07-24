#include <numeric>
#include <vector>
using namespace std;

class Solution {
 public:
  bool canPartition(vector<int>& nums) {
    int sum = accumulate(nums.cbegin(), nums.cend(), 0);
    if (sum % 2 == 1) {
      return false;
    }
    vector<bool> dp(sum, false);
    dp[0] = true;
    for (int i = 0; i < nums.size(); ++i) {
      for (int j = dp.size() - 1; j >= 0; --j) {
        if (dp[j] && j + nums[i] < dp.size()) {
          dp[j + nums[i]] = true;
        }
      }
    }
    return dp[sum / 2];
  }
};
