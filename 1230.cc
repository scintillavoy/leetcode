#include <vector>
using namespace std;

class Solution {
 public:
  double probabilityOfHeads(vector<double>& prob, int target) {
    int n = prob.size();
    vector<double> dp(target + 1);
    dp[0] = 1;
    for (int i = 0; i < n; ++i) {
      for (int j = target; j >= 1; --j) {
        dp[j] = dp[j - 1] * prob[i] + dp[j] * (1 - prob[i]);
      }
      dp[0] = dp[0] * (1 - prob[i]);
    }
    return dp[target];
  }
};
