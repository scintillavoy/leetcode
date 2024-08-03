#include <algorithm>
#include <vector>
using namespace std;

class Solution {
 public:
  int maxProfit(vector<int>& prices, int fee) {
    int profit = 0;
    int profit_holding = -prices[0];
    int max_profit = 0;
    for (int i = 1; i < prices.size(); ++i) {
      int next_profit = max(profit, profit_holding + prices[i] - fee);
      int next_profit_holding = max(profit_holding, profit - prices[i]);
      profit = next_profit;
      profit_holding = next_profit_holding;
      max_profit = max({max_profit, profit, profit_holding});
    }
    return max_profit;
  }
};
