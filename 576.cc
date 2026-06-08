#include <vector>
using namespace std;

#define MOD 1'000'000'007

class Solution {
 public:
  int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
    int num_of_paths = 0;
    vector<vector<int>> dp(m, vector<int>(n));
    dp[startRow][startColumn] = 1;
    for (int move = 0; move < maxMove; ++move) {
      vector<vector<int>> next_dp(m, vector<int>(n));
      for (int x = 0; x < m; ++x) {
        for (int y = 0; y < n; ++y) {
          if (dp[x][y] == 0) {
            continue;
          }
          for (int k = 0; k < 4; ++k) {
            int x2 = x + dx[k];
            int y2 = y + dy[k];
            if (x2 < 0 || x2 >= m || y2 < 0 || y2 >= n) {
              num_of_paths = (num_of_paths + dp[x][y]) % MOD;
            } else {
              next_dp[x2][y2] = (next_dp[x2][y2] + dp[x][y]) % MOD;
            }
          }
        }
      }
      dp = next_dp;
    }
    return num_of_paths;
  }

 private:
  const int dx[4] = {0, 0, -1, 1};
  const int dy[4] = {-1, 1, 0, 0};
};
