#include <unordered_set>
#include <vector>
using namespace std;

#define MOD 1'000'000'007

class Solution {
 public:
  int buildWall(int height, int width, vector<int>& bricks) {
    unordered_set<int> bricks_set(bricks.cbegin(), bricks.cend());
    vector<long long> dp(1 << (width - 1));
    for (int i = 0; i < dp.size(); ++i) {
      int length = 1;
      bool possible = true;
      for (int j = 1; j < dp.size(); j = j << 1) {
        if ((i & j) == 0) {
          ++length;
          continue;
        }
        if (bricks_set.count(length) == 0) {
          possible = false;
          break;
        }
        length = 1;
      }
      if (bricks_set.count(length) == 0) {
        possible = false;
      }
      if (possible) {
        dp[i] = 1;
      }
    }

    for (int h = 1; h < height; ++h) {
      vector<long long> next_dp(1 << (width - 1));
      for (int i = 0; i < dp.size(); ++i) {
        if (dp[i] == 0) {
          continue;
        }
        for (int j = 0; j < dp.size(); ++j) {
          if ((i & j) == 0) {
            next_dp[i] = (next_dp[i] + dp[j]) % MOD;
          }
        }
      }
      dp = next_dp;
    }

    long long answer = 0;
    for (int i = 0; i < dp.size(); ++i) {
      answer = (answer + dp[i]) % MOD;
    }
    return answer;
  }
};
