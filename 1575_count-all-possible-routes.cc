#include <cmath>
#include <vector>
using namespace std;

#define MOD 1000000007

class Solution {
 public:
  // DP (bottom-up)
  int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
    vector<vector<long>> dp(fuel + 1, vector<long>(locations.size(), 0));
    for (auto& x : dp) {
      x[finish] = 1;
    }
    for (int i = 0; i < dp.size(); ++i) {
      for (int j = 0; j < dp[0].size(); ++j) {
        for (int k = 0; k < dp[0].size(); ++k) {
          if (j == k) continue;
          if (i >= abs(locations[j] - locations[k])) {
            dp[i][j] =
                (dp[i][j] + dp[i - abs(locations[j] - locations[k])][k]) % MOD;
          }
        }
      }
    }
    return dp[fuel][start];
  }

  // DP (top-down)
  vector<vector<long>> dp;

  int solve(vector<int>& locations, int start, int finish, int fuel) {
    if (fuel < 0) return 0;
    if (dp[fuel][start] != -1) return dp[fuel][start];
    dp[fuel][start] = (start == finish) ? 1 : 0;
    for (int i = 0; i < locations.size(); ++i) {
      if (i == start) continue;
      dp[fuel][start] = (dp[fuel][start] +
                         solve(locations, i, finish,
                               fuel - abs(locations[start] - locations[i]))) %
                        MOD;
    }
    return dp[fuel][start];
  }

  int countRoutes2(vector<int>& locations, int start, int finish, int fuel) {
    dp = vector<vector<long>>(fuel + 1, vector<long>(locations.size(), -1));
    return solve(locations, start, finish, fuel);
  }
};

int main() { return 0; }
