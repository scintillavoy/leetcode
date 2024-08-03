#include <algorithm>
#include <string>
#include <vector>
using namespace std;

class Solution {
 public:
  int longestRepeatingSubstring(string s) {
    int n = s.size();
    vector<vector<int>> dp(n + 1, vector<int>(n + 1));
    int max_length = 0;
    for (int i = 1; i <= n; ++i) {
      for (int j = i + 1; j <= n; ++j) {
        if (s[i - 1] == s[j - 1]) {
          dp[i][j] = dp[i - 1][j - 1] + 1;
          max_length = max(max_length, dp[i][j]);
        }
      }
    }
    return max_length;
  }
};
