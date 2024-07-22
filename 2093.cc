#include <algorithm>
#include <functional>
#include <limits>
#include <queue>
#include <tuple>
#include <utility>
#include <vector>
using namespace std;

class Solution {
 public:
  int minimumCost(int n, vector<vector<int>>& highways, int discounts) {
    vector<vector<pair<int, int>>> graph(n);
    for (const auto& highway : highways) {
      graph[highway[0]].push_back({highway[2], highway[1]});
      graph[highway[1]].push_back({highway[2], highway[0]});
    }
    vector<vector<int>> distances(discounts + 1,
                                  vector<int>(n, numeric_limits<int>::max()));
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>,
                   greater<tuple<int, int, int>>>
        pq;
    distances[0][0] = 0;
    pq.push({0, 0, 0});
    while (!pq.empty()) {
      auto [curr_distance, curr, curr_discounts] = pq.top();
      pq.pop();
      if (distances[curr_discounts][curr] < curr_distance) {
        continue;
      }
      for (const auto [adj_weight, adj] : graph[curr]) {
        if (distances[curr_discounts][adj] >
            distances[curr_discounts][curr] + adj_weight) {
          distances[curr_discounts][adj] =
              distances[curr_discounts][curr] + adj_weight;
          pq.push({distances[curr_discounts][adj], adj, curr_discounts});
        }
        if (curr_discounts < discounts &&
            distances[curr_discounts + 1][adj] >
                distances[curr_discounts][curr] + adj_weight / 2) {
          distances[curr_discounts + 1][adj] =
              distances[curr_discounts][curr] + adj_weight / 2;
          pq.push(
              {distances[curr_discounts + 1][adj], adj, curr_discounts + 1});
        }
      }
    }
    int min_distance = numeric_limits<int>::max();
    for (int i = 0; i <= discounts; ++i) {
      min_distance = min(min_distance, distances[i][n - 1]);
    }
    if (min_distance == numeric_limits<int>::max()) {
      return -1;
    }
    return min_distance;
  }
};
