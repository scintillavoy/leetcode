#include <algorithm>
#include <vector>
using namespace std;

class Solution {
 public:
  int minNumberOfSemesters(int n, vector<vector<int>>& relations, int k) {
    vector<int> prerequisites(n);
    for (const auto& relation : relations) {
      prerequisites[relation[1] - 1] |= 1 << relation[0] - 1;
    }
    vector<int> dp(1 << n, n);
    dp[0] = 0;
    for (int i = 0; i < (1 << n); ++i) {
      int available = 0;
      for (int j = 0; j < n; ++j) {
        if ((i & prerequisites[j]) == prerequisites[j]) {
          available |= 1 << j;
        }
      }
      available &= ~i;
      for (int j = available; j > 0; j = (j - 1) & available) {
        if (count_ones(j) <= k) {
          dp[i | j] = min(dp[i | j], dp[i] + 1);
        }
      }
    }
    return dp.back();
  }

 private:
  int count_ones(int bits) {
    if (bits == 0) {
      return 0;
    }
    return 1 + count_ones(bits & (bits - 1));
  }
};
