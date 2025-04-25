#include <vector>
using namespace std;

class Solution {
 public:
  long long getDescentPeriods(vector<int>& prices) {
    long long total = 1;
    long long current = 1;
    for (int i = 1; i < prices.size(); ++i) {
      if (prices[i - 1] - 1 == prices[i]) {
        ++current;
      } else {
        current = 1;
      }
      total += current;
    }
    return total;
  }
};
