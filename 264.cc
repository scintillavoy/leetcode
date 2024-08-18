#include <algorithm>
#include <vector>
using namespace std;

class Solution {
 public:
  int nthUglyNumber(int n) {
    vector<int> dp(n + 1);
    dp[1] = 1;
    int idx2 = 1, idx3 = 1, idx5 = 1;
    for (int i = 2; i < n + 1; ++i) {
      dp[i] = min({dp[idx2] * 2, dp[idx3] * 3, dp[idx5] * 5});
      if (dp[i] == dp[idx2] * 2) {
        ++idx2;
      }
      if (dp[i] == dp[idx3] * 3) {
        ++idx3;
      }
      if (dp[i] == dp[idx5] * 5) {
        ++idx5;
      }
    }
    return dp[n];
  }
};
