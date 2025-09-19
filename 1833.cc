#include <algorithm>
#include <vector>
using namespace std;

class Solution {
 public:
  int maxIceCream(vector<int>& costs, int coins) {
    vector<int> counts(*max_element(costs.begin(), costs.end()) + 1);
    for (const auto cost : costs) {
      ++counts[cost];
    }
    int max_count = 0;
    for (int i = 0; i < counts.size(); ++i) {
      while (counts[i] > 0 && coins - i >= 0) {
        coins -= i;
        --counts[i];
        ++max_count;
      }
    }
    return max_count;
  }
};
