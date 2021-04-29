#include <algorithm>
#include <vector>
using namespace std;

class Solution {
 public:
  int rob(vector<int>& nums) {
    int n = nums.size();
    if (n < 2) return n ? nums[0] : 0;
    // dp[0][*]: rob nums[0]
    // dp[1][*]: do not rob nums[0]
    // dp[*][0]: previous
    // dp[*][1]: current
    int dp[2][2] = {{nums[0], nums[0]}, {0, nums[1]}};
    for (int i = 2; i < n - 1; ++i) {
      int temp = max(dp[0][1], dp[0][0] + nums[i]);
      dp[0][0] = dp[0][1];
      dp[0][1] = temp;
      temp = max(dp[1][1], dp[1][0] + nums[i]);
      dp[1][0] = dp[1][1];
      dp[1][1] = temp;
    }
    dp[1][1] = max(dp[1][1], dp[1][0] + nums[n - 1]);
    return max(dp[0][1], dp[1][1]);
  }
};

int main() { return 0; }
