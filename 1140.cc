#include <algorithm>
#include <vector>
using namespace std;

class Solution {
 public:
  int stoneGameII(vector<int>& piles) {
    int n = piles.size();
    vector<int> suffix_sum(n + 1);
    for (int i = n - 1; i >= 0; --i) {
      suffix_sum[i] = suffix_sum[i + 1] + piles[i];
    }
    vector<vector<int>> dp(n + 1, vector<int>(n + 1));
    for (int i = 0; i <= n; ++i) {
      dp[i][n] = suffix_sum[i];
    }
    for (int i = n - 1; i >= 0; --i) {
      for (int j = n - 1; j >= 0; --j) {
        for (int X = 1; X <= 2 * j && i + X <= n; ++X) {
          dp[i][j] = max(dp[i][j], suffix_sum[i] - dp[i + X][max(j, X)]);
        }
      }
    }
    return dp[0][1];
  }
};
