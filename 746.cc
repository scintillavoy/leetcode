#include <algorithm>
#include <vector>
using namespace std;

class Solution {
 public:
  int minCostClimbingStairs(vector<int>& cost) {
    vector<int> dp(cost.size() + 1);
    for (int i = 2; i < dp.size(); ++i) {
      dp[i] = min(dp[i - 2] + cost[i - 2], dp[i - 1] + cost[i - 1]);
    }
    return dp.back();
  }
};
