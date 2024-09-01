#include <algorithm>
#include <limits>
#include <vector>
using namespace std;

class Solution {
 public:
  int coinChange(vector<int>& coins, int amount) {
    vector<int> fewest(amount + 1, numeric_limits<int>::max());
    fewest[0] = 0;
    for (int i = 0; i < fewest.size(); ++i) {
      if (fewest[i] == numeric_limits<int>::max()) {
        continue;
      }
      for (const auto coin : coins) {
        if ((long long)i + coin >= fewest.size()) {
          continue;
        }
        fewest[i + coin] = min(fewest[i + coin], fewest[i] + 1);
      }
    }
    return fewest[amount] == numeric_limits<int>::max() ? -1 : fewest[amount];
  }
};
