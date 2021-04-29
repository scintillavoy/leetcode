#include <algorithm>
#include <vector>
using namespace std;

// Solution using dp + binary search
// time complexity: O(nlogn)
class Solution {
 public:
  int maxEnvelopes(vector<vector<int>> &envelopes) {
    sort(envelopes.begin(), envelopes.end(),
         [](vector<int> &a, vector<int> &b) {
           return a[0] < b[0] || (a[0] == b[0] && a[1] > b[1]);
         });
    vector<int> dp;
    for (const auto &x : envelopes) {
      auto it = lower_bound(dp.begin(), dp.end(), x[1]);
      if (it == dp.end()) {
        dp.push_back(x[1]);
      } else if (*it > x[1]) {
        *it = x[1];
      }
    }
    return dp.size();
  }
};

// Solution using simple dp
// time complexity: O(n^2)
class Solution2 {
 public:
  int maxEnvelopes(vector<vector<int>> &envelopes) {
    int n = envelopes.size();
    sort(envelopes.begin(), envelopes.end(),
         [](vector<int> &a, vector<int> &b) { return a[0] < b[0]; });
    vector<int> dp(n, 0);
    for (int i = 0; i < n; ++i) {
      int max_val = 0;
      for (int j = i - 1; j >= 0; --j) {
        if (envelopes[j][0] < envelopes[i][0] &&
            envelopes[j][1] < envelopes[i][1]) {
          max_val = max(max_val, dp[j]);
        }
      }
      dp[i] = max_val + 1;
    }
    return *max_element(dp.cbegin(), dp.cend());
  }
};

int main() { return 0; }
