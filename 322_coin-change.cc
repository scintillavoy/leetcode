#include <algorithm>
#include <limits>
#include <vector>
using namespace std;

class Solution {
 public:
  int coinChange(vector<int>& coins, int amount) {
    vector<int> dp(amount + 1, numeric_limits<int>::max());
    dp[0] = 0;
    for (int i = 1; i <= amount; ++i) {
      for (auto const& c : coins) {
        if (c <= i && dp[i - c] != numeric_limits<int>::max()) {
          dp[i] = min(dp[i], dp[i - c] + 1);
        }
      }
    }
    return (dp[amount] == numeric_limits<int>::max() ? -1 : dp[amount]);
  }
};

int main() { return 0; }
