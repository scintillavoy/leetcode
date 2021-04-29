#include <algorithm>
#include <vector>
using namespace std;

class Solution {
 public:
  int maxProfit(vector<int>& prices) {
    int left = 0;
    int max_profit = 0;
    for (int i = 1; i < prices.size(); ++i) {
      if (prices[left] > prices[i]) {
        left = i;
      } else {
        max_profit = max(max_profit, prices[i] - prices[left]);
      }
    }
    return max_profit;
  }
};

int main() { return 0; }
