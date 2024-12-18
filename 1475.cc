#include <stack>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<int> finalPrices(vector<int>& prices) {
    vector<int> result(prices.size());
    stack<int> stk;
    for (int i = prices.size() - 1; i >= 0; --i) {
      while (!stk.empty() && stk.top() > prices[i]) {
        stk.pop();
      }
      result[i] = prices[i] - (stk.empty() ? 0 : stk.top());
      stk.push(prices[i]);
    }
    return result;
  }
};
