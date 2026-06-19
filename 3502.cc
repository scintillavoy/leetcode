#include <algorithm>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<int> minCosts(vector<int>& cost) {
    int min_cost = cost[0];
    for (int i = 1; i < cost.size(); ++i) {
      min_cost = min(min_cost, cost[i]);
      cost[i] = min_cost;
    }
    return cost;
  }
};
