#include <algorithm>
#include <vector>
using namespace std;

class Solution {
 public:
  int maximumWealth(vector<vector<int>>& accounts) {
    int max_wealth = 0;
    for (const auto& account : accounts) {
      int total_money = 0;
      for (const auto money : account) {
        total_money += money;
      }
      max_wealth = max(max_wealth, total_money);
    }
    return max_wealth;
  }
};
