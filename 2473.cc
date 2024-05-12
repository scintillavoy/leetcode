#include <functional>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<long long> minCost(int n, vector<vector<int>>& roads,
                            vector<int>& appleCost, int k) {
    vector<vector<pair<int, int>>> graph(n);
    for (const auto& road : roads) {
      graph[road[0] - 1].push_back({road[2], road[1] - 1});
      graph[road[1] - 1].push_back({road[2], road[0] - 1});
    }
    priority_queue<pair<long long, int>, vector<pair<long long, int>>,
                   greater<pair<long long, int>>>
        pq;
    vector<long long> distances(n);
    for (int i = 0; i < n; ++i) {
      distances[i] = appleCost[i];
      pq.push({appleCost[i], i});
    }
    while (!pq.empty()) {
      auto [curr_distance, curr] = pq.top();
      pq.pop();
      if (distances[curr] < curr_distance) {
        continue;
      }
      for (const auto& [adj_distance, adj] : graph[curr]) {
        if (distances[adj] <= curr_distance + adj_distance * (k + 1)) {
          continue;
        }
        distances[adj] = curr_distance + adj_distance * (k + 1);
        pq.push({distances[adj], adj});
      }
    }
    return distances;
  }
};
