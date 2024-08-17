#include <algorithm>
#include <vector>
using namespace std;

class Solution {
 public:
  long long maxPoints(vector<vector<int>>& points) {
    int m = points.size();
    int n = points[0].size();
    vector<long long> dp(n);
    for (int i = 0; i < n; ++i) {
      dp[i] = points[0][i];
    }
    for (int i = 1; i < m; ++i) {
      vector<long long> prev(dp);
      long long best = dp[0];
      for (int j = 1; j < n; ++j) {
        --best;
        if (best < prev[j]) {
          best = prev[j];
        } else {
          prev[j] = best;
        }
      }
      best = dp[n - 1];
      for (int j = n - 2; j >= 0; --j) {
        --best;
        if (best < prev[j]) {
          best = prev[j];
        } else {
          prev[j] = best;
        }
      }
      for (int j = 0; j < n; ++j) {
        dp[j] = points[i][j] + prev[j];
      }
    }
    return *max_element(dp.cbegin(), dp.cend());
  }
};
