#include <algorithm>
#include <vector>
using namespace std;

class Solution {
 public:
  int minCostII(vector<vector<int>>& costs) {
    int n = costs.size();
    int k = costs[0].size();
    vector<int> min_costs(k);
    for (int i = 0; i < k; ++i) {
      min_costs[i] = costs[0][i];
    }
    for (int i = 1; i < n; ++i) {
      pair<int, int> min_indices;
      if (min_costs[0] < min_costs[1]) {
        min_indices = {0, 1};
      } else {
        min_indices = {1, 0};
      }
      for (int j = 2; j < k; ++j) {
        if (min_costs[j] < min_costs[min_indices.first]) {
          min_indices = {j, min_indices.first};
        } else if (min_costs[j] < min_costs[min_indices.second]) {
          min_indices.second = j;
        }
      }
      vector<int> next_min_costs(k);
      for (int j = 0; j < k; ++j) {
        if (j != min_indices.first) {
          next_min_costs[j] = costs[i][j] + min_costs[min_indices.first];
        } else {
          next_min_costs[j] = costs[i][j] + min_costs[min_indices.second];
        }
      }
      min_costs = next_min_costs;
    }
    return *min_element(min_costs.begin(), min_costs.end());
  }
};
