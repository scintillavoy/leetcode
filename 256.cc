#include <algorithm>
#include <vector>
using namespace std;

class Solution {
 public:
  int minCost(vector<vector<int>>& costs) {
    vector<int> min_costs = costs[0];
    for (int i = 1; i < costs.size(); ++i) {
      min_costs = {
          costs[i][0] + min(min_costs[1], min_costs[2]),
          costs[i][1] + min(min_costs[2], min_costs[0]),
          costs[i][2] + min(min_costs[0], min_costs[1]),
      };
    }
    return *min_element(min_costs.begin(), min_costs.end());
  }
};
