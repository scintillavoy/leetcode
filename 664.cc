#include <algorithm>
#include <string>
#include <vector>
using namespace std;

class Solution {
 public:
  int strangePrinter(string s) {
    int n = s.size();
    vector<vector<int>> dp(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
      dp[i][i] = 1;
    }
    for (int length = 2; length <= n; ++length) {
      for (int start = 0; start + length - 1 < n; ++start) {
        int end = start + length - 1;
        dp[start][end] = length;
        for (int split = start; split < end; ++split) {
          int count = dp[start][split] + dp[split + 1][end];
          if (s[split] == s[end]) {
            --count;
          }
          dp[start][end] = min(dp[start][end], count);
        }
      }
    }
    return dp[0][n - 1];
  }
};
