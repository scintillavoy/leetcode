#include <algorithm>
#include <functional>
#include <limits>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

class Solution {
 public:
  int minimumDistance(int n, vector<vector<int>>& edges, int s,
                      vector<int>& marked) {
    vector<vector<pair<int, int>>> graph(n);
    for (const auto& edge : edges) {
      graph[edge[0]].push_back({edge[2], edge[1]});
    }
    vector<int> distances(n, numeric_limits<int>::max());
    priority_queue<pair<int, int>, vector<pair<int, int>>,
                   greater<pair<int, int>>>
        pq;
    distances[s] = 0;
    pq.push({0, s});
    while (!pq.empty()) {
      auto [curr_distance, curr] = pq.top();
      pq.pop();
      if (distances[curr] < curr_distance) {
        continue;
      }
      for (const auto [weight, adj] : graph[curr]) {
        if (distances[adj] > distances[curr] + weight) {
          distances[adj] = distances[curr] + weight;
          pq.push({distances[adj], adj});
        }
      }
    }
    int min_distance = numeric_limits<int>::max();
    for (int i = 0; i < marked.size(); ++i) {
      min_distance = min(min_distance, distances[marked[i]]);
    }
    return min_distance == numeric_limits<int>::max() ? -1 : min_distance;
  }
};
