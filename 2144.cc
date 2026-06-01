#include <algorithm>
#include <vector>
using namespace std;

class Solution {
 public:
  int minimumCost(vector<int>& cost) {
    sort(cost.rbegin(), cost.rend());
    int total_cost = 0;
    for (int i = 0; i < cost.size(); ++i) {
      if (i % 3 == 2) {
        continue;
      }
      total_cost += cost[i];
    }
    return total_cost;
  }
};
