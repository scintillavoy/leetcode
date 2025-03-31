#include <algorithm>
#include <vector>
using namespace std;

class Solution {
 public:
  long long putMarbles(vector<int>& weights, int k) {
    vector<int> costs(weights.size() - 1);
    for (int i = 1; i < weights.size(); ++i) {
      costs[i - 1] = weights[i - 1] + weights[i];
    }
    sort(costs.begin(), costs.end());
    long long min_cost = 0;
    long long max_cost = 0;
    for (int i = 0; i < k - 1; ++i) {
      min_cost += costs[i];
      max_cost += costs[costs.size() - 1 - i];
    }
    return max_cost - min_cost;
  }
};
