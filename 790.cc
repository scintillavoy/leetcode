#include <vector>
using namespace std;

#define MOD 1'000'000'007

class Solution {
 public:
  int numTilings(int n) {
    vector<long long> dp{1, 1, 2, 5};
    if (n < 4) {
      return dp[n];
    }
    for (int i = 4; i <= n; ++i) {
      dp[0] = (dp[0] + dp[1]) % MOD;
      dp[1] = dp[2];
      dp[2] = dp[3];
      dp[3] = (dp[0] * 2 + dp[1] + dp[2]) % MOD;
    }
    return dp.back();
  }
};
