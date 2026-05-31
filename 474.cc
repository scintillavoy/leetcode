#include <algorithm>
#include <string>
#include <vector>
using namespace std;

class Solution {
 public:
  int findMaxForm(vector<string>& strs, int m, int n) {
    vector<vector<int>> dp(m + 1, vector<int>(n + 1));
    for (const auto& s : strs) {
      int num_of_zeros = 0;
      for (const auto c : s) {
        if (c == '0') {
          ++num_of_zeros;
        }
      }
      int num_of_ones = s.size() - num_of_zeros;
      for (int i = m; i >= num_of_zeros; --i) {
        for (int j = n; j >= num_of_ones; --j) {
          dp[i][j] = max(dp[i][j], dp[i - num_of_zeros][j - num_of_ones] + 1);
        }
      }
    }
    return dp[m][n];
  }
};
